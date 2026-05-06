// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.h"

#include "ProjectileSpawner.generated.h"

UCLASS(Blueprintable)
class TOYSOLDIERS_API AProjectileSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileSpawner();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AProjectileBase> ProjectileToSpawn;// = AProjectileBase::StaticClass();

	UFUNCTION(BlueprintCallable)
	void SpawnProjectile();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
