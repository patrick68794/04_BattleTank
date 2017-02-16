// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	ATank* GetControlledTank() const;

private:
	//start the tank moving the barrel to shoot where crosshair is
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector&) const;

	bool GetLookDirection(FVector2D screenLocation, FVector& lookDirection) const;

	bool GetLookVectorHitLocation(FVector lookDirection, FVector& hitLocation) const;

	UPROPERTY(EditAnywhere)
	float crosshairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float crosshairYLocation = 0.33333f;

	UPROPERTY(EditAnywhere)
	float lineTraceRange = 1000000.0f;
};
