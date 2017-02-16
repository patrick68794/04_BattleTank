// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController begin play"));

	auto tank = GetControlledTank();

	if (!tank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController no tank"));

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController controlling %s"), *tank->GetName());
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}