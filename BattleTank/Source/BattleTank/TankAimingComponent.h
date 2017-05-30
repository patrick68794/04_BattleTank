// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Enum for aim state
UENUM()
enum class EFiringState : uint8
{
	Reloading, Aiming, Locked
};

class UTankBarrel; // forward declaration
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* barrelToSet);

	void SetTurretReference(UTankTurret* turretToSet);

	void AimAt(FVector hitLocation, float launchSpeed);

	// TODO add SetTurretReference

protected:
	UPROPERTY(BluePrintReadOnly, Category = "State")
		EFiringState firingState = EFiringState::Reloading;

private:
	UTankBarrel* barrel = nullptr;

	UTankTurret* turret = nullptr;

	void MoveBarrel(FVector aimDirection);

	
};
