// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1is max down movement, +1 is max up movement
	void ElevateBarrel(float relativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float maxDegreesPerSecond = 10;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float maxElevation = 30;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float minElevation = -1;

};
