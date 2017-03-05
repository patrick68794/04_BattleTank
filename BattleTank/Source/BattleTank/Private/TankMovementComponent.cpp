// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialize(UTankTrack * leftToSet, UTankTrack* rightToSet)
{


	leftTrack = leftToSet;
	rightTrack = rightToSet;
}

void UTankMovementComponent::IntendMoveForward(float movementSpeed)
{
	if (!leftTrack || !rightTrack)
	{
		return;
	}
	leftTrack->SetThrottle(movementSpeed);
	rightTrack->SetThrottle(movementSpeed);
}

void UTankMovementComponent::IntendTurnRight(float movementSpeed)
{
	if (!leftTrack || !rightTrack)
	{
		return;
	}
	leftTrack->SetThrottle(movementSpeed);
	rightTrack->SetThrottle(-movementSpeed);
}
