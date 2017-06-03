// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetThrottle(float throttle);
	

	// max force per track in newtons
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float trackMaxDrivingForce = 310000; //62,000 kg tank at 5 m/s^2
	
};
