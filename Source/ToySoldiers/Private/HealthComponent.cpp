// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	Owner = GetOwner();
}

void UHealthComponent::TakeDamage(float DamageAmount)
{	
	CurrentHealth -= DamageAmount;
	OnTakeDamage.Broadcast(DamageAmount);
	if (CurrentHealth <= 0.f)
	{
		Die();
	}
}

void UHealthComponent::Heal(float HealAmount, bool ignoreMaxHealth)
{
	CurrentHealth += HealAmount;
	OnHeal.Broadcast(HealAmount, ignoreMaxHealth);
	if (!ignoreMaxHealth && CurrentHealth > MaxHealth)
	{
		CurrentHealth = MaxHealth;
	}
}

void UHealthComponent::Die()
{
	OnDeath.Broadcast();
	if (Owner)
	{
		Owner->Destroy();
	}
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

