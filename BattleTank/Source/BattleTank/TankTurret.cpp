// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"


void UTankTurret::RotateTurret(float relativeSpeed)
{
	relativeSpeed = FMath::Clamp<float>(relativeSpeed, -1, 1);
	auto rotationChange = relativeSpeed * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto newRotation = RelativeRotation.Yaw + rotationChange;
	SetRelativeRotation(FRotator(0, newRotation, 0));
}

