// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	aimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	//no need to protect pointers added during construction
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::AimAt(FVector hitLocation)
{
	aimingComponent->AimAt(hitLocation, launchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* barrelToSet)
{
	aimingComponent->SetBarrelReference(barrelToSet);
}

void ATank::SetTurretReference(UTankTurret* turretToSet)
{
	aimingComponent->SetTurretReference(turretToSet);
}

void ATank::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("firing"));
}