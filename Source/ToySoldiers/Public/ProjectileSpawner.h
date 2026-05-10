// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ProjectileBase.h"

#include "ProjectileSpawner.generated.h"

class UStatMultipliers;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TOYSOLDIERS_API UProjectileSpawner : public USceneComponent
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	UProjectileSpawner();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AProjectileBase> ProjectileToSpawn;// = AProjectileBase::StaticClass();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxBulletsPerSecond;

	UPROPERTY(BlueprintReadOnly)
	float timeBetweenShots;
	float timeOfLastShot;

	UFUNCTION(BlueprintCallable, meta = (ReturnDisplayName = "Ref to fired proj"))
	AProjectileBase* SpawnProjectile();

	UStatMultipliers* statMultipliers;

};
