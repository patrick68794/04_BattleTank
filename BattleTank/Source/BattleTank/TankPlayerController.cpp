// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

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

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}

	// get world location if linetrace through crosshair
	//if it hits landscape
		//tell controlled tank to aim at this point
}