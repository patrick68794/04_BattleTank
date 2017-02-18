// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
}

void UTankAimingComponent::AimAt(FVector hitLocation, float launchSpeed)
{
	if (!barrel) { return; }
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
		ESuggestProjVelocityTraceOption::DoNotTrace
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
	this->barrel = barrelToSet;
}

void UTankAimingComponent::MoveBarrel(FVector aimDirection)
{
	// determine rotation needed to point the barrel in the correct direction
	auto barrelRotation = barrel->GetForwardVector().Rotation();
	auto aimAsRotator = aimDirection.Rotation();
	auto deltaRotator = aimAsRotator - barrelRotation;

	barrel->ElevateBarrel(5);
}