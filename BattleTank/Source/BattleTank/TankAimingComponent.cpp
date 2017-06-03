// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true; // TODO should this tick?
}

void UTankAimingComponent::Initialize(UTankBarrel* barrelToSet, UTankTurret* turretToSet)
{
	barrel = barrelToSet;
	turret = turretToSet;
}

void UTankAimingComponent::AimAt(FVector hitLocation)
{
	if (!ensure(barrel)) { return; }
	if (!ensure(turret)) { return; }
	FVector launchVelocity;
	FVector startLocation = barrel->GetSocketLocation(FName("Projectile"));

	// calculate the launchVelocity
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		launchVelocity,
		startLocation,
		hitLocation,
		launchSpeed,
		false,
		0.0f,
		0.0f,
		ESuggestProjVelocityTraceOption::DoNotTrace // must be present to prevent bug
	);
	if (bHaveAimSolution)
	{
		auto aimDirection = launchVelocity.GetSafeNormal();
		auto tankName = GetOwner()->GetName();
		MoveBarrel(aimDirection);
	}
	
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* barrelToSet)
{
	if (!ensure(barrelToSet)) { return; }
	this->barrel = barrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret* turretToSet)
{
	if (!ensure(turretToSet)) { return; }
	this->turret = turretToSet;
}

void UTankAimingComponent::MoveBarrel(FVector aimDirection)
{
	if (!ensure(barrel) || !ensure(turret)) { return; }
	// determine rotation needed to point the barrel in the correct direction
	auto barrelRotation = barrel->GetForwardVector().Rotation();
	auto aimAsRotator = aimDirection.Rotation();
	auto deltaRotator = aimAsRotator - barrelRotation;

	barrel->ElevateBarrel(deltaRotator.Pitch);
	turret->RotateTurret(deltaRotator.Yaw);
}

void UTankAimingComponent::Fire()
{
	if (!ensure(barrel && ProjectileBlueprint)) { return; }
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (isReloaded)
	{
		// Spawn a projectile at the socket location on the barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			barrel->GetSocketLocation(FName("Projectile")),
			barrel->GetSocketRotation(FName("Projectile"))
			);

		Projectile->LaunchProjectile(launchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}