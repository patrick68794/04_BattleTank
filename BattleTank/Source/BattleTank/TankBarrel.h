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
	void ElevateBarrel(float degPerSecond);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float maxDegreesPerSecond = 20;

	UPROPERTY(EditAnywhere, Category = Setup)
		float maxElevation = 30;

	UPROPERTY(EditAnywhere, Category = Setup)
		float minElevation = -1;

};
