// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::IntendMoveForward(float movementSpeed)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward amount: %f"), movementSpeed);
}


