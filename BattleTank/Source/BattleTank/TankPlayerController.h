// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* aimingCompRef);

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	//start the tank moving the barrel to shoot where crosshair is
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector&) const;

	bool GetLookDirection(FVector2D screenLocation, FVector& lookDirection) const;

	bool GetLookVectorHitLocation(FVector lookDirection, FVector& hitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float crosshairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float crosshairYLocation = 0.33333f;

	UPROPERTY(EditDefaultsOnly)
	float lineTraceRange = 1000000.0f;
};
