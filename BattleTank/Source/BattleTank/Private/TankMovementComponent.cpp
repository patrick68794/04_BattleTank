// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialize(UTankTrack * leftToSet, UTankTrack* rightToSet)
{
	if (!leftToSet || !rightToSet)
	{
		return;
	}

	leftTrack = leftToSet;
	rightTrack = rightToSet;
}

void UTankMovementComponent::IntendMoveForward(float movementSpeed)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward amount: %f"), movementSpeed);

	leftTrack->SetThrottle(movementSpeed);
	rightTrack->SetThrottle(movementSpeed);
}


