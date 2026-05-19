// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileSpawner.h"
#include "StatMultipliers.h"
#include <sstream>
#include "EntityUpgradeComponent.h"

// Sets default values
UProjectileSpawner::UProjectileSpawner()
{
	ProjectileToSpawn = AProjectileBase::StaticClass();	

	MaxBulletsPerSecond = 3.f;
	
}

// Called when the game starts or when spawned
void UProjectileSpawner::BeginPlay()
{
	Super::BeginPlay();

	//log to screen 
	timeBetweenShots = 1.f / MaxBulletsPerSecond;
	timeOfLastShot = 0.f;
	UEntityUpgradeComponent* upgradeComp = GetOwner()->FindComponentByClass<UEntityUpgradeComponent>();

	// random comment
	if (upgradeComp)
	{
		statMultipliers = upgradeComp->StatData;
	}

	AActor* Owner = GetOwner();
	APawn* InstigatorPawn = nullptr;

	// Walk up attachment hierarchy (weapon → pawn)
	for (AActor* Actor = Owner; Actor; Actor = Actor->GetAttachParentActor())
	{
		if (APawn* Pawn = Cast<APawn>(Actor))
		{
			InstigatorPawn = Pawn;
			break;
		}
	}

	Instigator = InstigatorPawn;
}

void UProjectileSpawner::SetMaxBulletsPerSecond(float newMax)
{
	if (MaxBulletsPerSecond == newMax)
		return;

	MaxBulletsPerSecond = newMax;

	timeBetweenShots = 1.f / MaxBulletsPerSecond;
	
	timeOfLastShot = 0.f;
}

AProjectileBase* UProjectileSpawner::SpawnProjectile()
{
	float scaledTime = timeBetweenShots;

	if (statMultipliers != nullptr)
	{
		scaledTime /= statMultipliers->FireRateMultiplier;
	}

	if (timeOfLastShot + scaledTime >= GetWorld()->GetTimeSeconds())
	{
		return nullptr;
	}

	if (Instigator == nullptr)
	{
		return nullptr;
	}

	if (IsValid(ProjectileToSpawn))
	{


		AProjectileBase* spawned = GetWorld()->SpawnActorDeferred<AProjectileBase>(ProjectileToSpawn, GetComponentTransform());



		spawned->SetInstigator(Instigator);
		
		if (statMultipliers)
		{
			spawned->Damage *= statMultipliers->DamageMultiplier;
			// projectile stat multipliers can be added here as needed
		}

		timeOfLastShot = GetWorld()->GetTimeSeconds();

		spawned->FinishSpawning(GetComponentTransform());
		return spawned;
	}
	return nullptr;
}

