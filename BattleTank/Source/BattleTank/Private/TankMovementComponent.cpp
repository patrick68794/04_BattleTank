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
	if (!leftTrack || !rightTrack) {return;}
	leftTrack->SetThrottle(movementSpeed);
	rightTrack->SetThrottle(movementSpeed);
}

void UTankMovementComponent::IntendTurnRight(float movementSpeed)
{
	if (!leftTrack || !rightTrack) {return;}
	leftTrack->SetThrottle(movementSpeed);
	rightTrack->SetThrottle(-movementSpeed);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) 
{
	// no need to call Super since functionality is being replaced
	auto tankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto aiForwardIntention = MoveVelocity.GetSafeNormal();

	auto rightThrow = FVector::CrossProduct(tankForward, aiForwardIntention).Z;
	IntendTurnRight(rightThrow);

	auto forwardThrow = FVector::DotProduct(tankForward, aiForwardIntention);
	IntendMoveForward(forwardThrow);
	//UE_LOG(LogTemp, Warning, TEXT("%s moving at %s m/s"), *tankName, *moveVelocityString);
}