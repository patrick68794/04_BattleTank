// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * Responsible for driving tank tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendMoveForward(float movementSpeed);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendTurnRight(float movementSpeed);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankTrack* leftToSet, UTankTrack* rightToSet);

private:
	// called from the pathfinding logic by the AI controllers
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

	UTankTrack* leftTrack = nullptr;
	UTankTrack* rightTrack = nullptr;
};
