// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::ElevateBarrel(float relativeSpeed)
{
	// use a rotator on socket to move barrel to correct position
	// given max elevation and frame time
	relativeSpeed = FMath::Clamp<float>(relativeSpeed, -1, 1);

	auto elevationChange = relativeSpeed * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto rawNewElevation = RelativeRotation.Pitch + elevationChange;
	auto elevation = FMath::Clamp<float>(rawNewElevation, minElevation, maxElevation);
	SetRelativeRotation(FRotator(elevation, 0, 0));
}



