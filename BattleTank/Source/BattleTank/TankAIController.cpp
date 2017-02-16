// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AIController begin play"));

	auto tank = GetControlledTank();

	if (!tank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController no tank"));

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController controlling %s"), *tank->GetName());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
