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

// forward declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialize(UTankBarrel* barrelToSet, UTankTurret* turretToSet);

	void SetBarrelReference(UTankBarrel* barrelToSet);

	void SetTurretReference(UTankTurret* turretToSet);

	void AimAt(FVector hitLocation);

	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();

	bool IsBarrelMoving();

protected:
	UPROPERTY(BluePrintReadOnly, Category = "State")
		EFiringState firingState = EFiringState::Reloading;

private:

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float launchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;

	UTankBarrel* barrel = nullptr;

	UTankTurret* turret = nullptr;

	void MoveBarrel(FVector aimDirection);

	FVector aimDirection;
};
