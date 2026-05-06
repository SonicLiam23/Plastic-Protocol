// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileSpawner.h"

// Sets default values
AProjectileSpawner::AProjectileSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileToSpawn = AProjectileBase::StaticClass();
	
}

// Called when the game starts or when spawned
void AProjectileSpawner::BeginPlay()
{
	Super::BeginPlay();
	// DEBUG: Enable input for testing purposes, should be removed later
	EnableInput(GetWorld()->GetFirstPlayerController());
}

// Called every frame
void AProjectileSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProjectileSpawner::SpawnProjectile()
{
	if (IsValid(ProjectileToSpawn))
	{
		FVector spawnLocation = GetActorLocation();
		FRotator spawnRotation = GetActorRotation();
		GetWorld()->SpawnActor<AProjectileBase>(ProjectileToSpawn, spawnLocation, spawnRotation);
	}
}

