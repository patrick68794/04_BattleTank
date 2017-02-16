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

	FVector hitLocation; //out parameter

	if (GetSightRayHitLocation(hitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("hitLocation: %s"), *hitLocation.ToString());
			//tell controlled tank to aim at this point
	}
	
}

// get world location of linetrace through crosshair, if it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& hitLocation) const
{
	// find the crosshair position
	int32 viewportSizeX, viewportSizeY;
	GetViewportSize(viewportSizeX, viewportSizeY);
	FVector lookDirection;
	auto screenLocation = FVector2D(viewportSizeX * crosshairXLocation, viewportSizeY * crosshairYLocation);
	if (GetLookDirection(screenLocation, lookDirection))
	{
		// line trace along that look direction and see what gets hit(max range)
		GetLookVectorHitLocation(lookDirection, hitLocation);
		UE_LOG(LogTemp, Warning, TEXT("world direction: %s"), *hitLocation.ToString());
	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D screenLocation, FVector& lookDirection) const
{
	FVector worldLocation;
	//De-project screen position of the crosshair to a world direction
	return DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, worldLocation, lookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector lookDirection, FVector& hitLocation) const
{
	FHitResult hitResult;
	auto startLocation = PlayerCameraManager->GetCameraLocation();
	auto endLocation = startLocation + (lookDirection * lineTraceRange);
	FCollisionQueryParams traceParameters(FName(TEXT("")), false, GetOwner());
	if (GetWorld()->LineTraceSingleByChannel(hitResult, startLocation, endLocation, ECC_Visibility))
	{
		hitLocation = hitResult.Location;
		return true;
	}
	hitLocation = FVector(0);
	return false;
}

