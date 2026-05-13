// Fill out your copyright notice in the Description page of Project Settings.
#include "StatMultipliers.h"
#include <random>

UStatMultipliers::UStatMultipliers()
{
	DamageMultiplier = 1.f;
	FireRateMultiplier = 1.f;
	MaxHealthMultiplier = 1.f;

	CurrentXP = 0.f;
	NextLevelXP = 0.f;
	PlayerLevel = 1.f;

}

float& UStatMultipliers::GetRandomStat()
{
	srand(time(NULL));

	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Level up"));

	int stat = rand() % 4;

	switch (stat)
	{
	case 0:
		return DamageMultiplier;
		break; // shouldnt need break but oh well

	case 1:
		return FireRateMultiplier;

	case 2:
		return MaxHealthMultiplier;
	}

	return DamageMultiplier;
}
