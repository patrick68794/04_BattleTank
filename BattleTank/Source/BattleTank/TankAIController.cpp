// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	auto playerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto controlledTank = Cast<ATank>(GetPawn());
	if (playerTank)
	{
		MoveToActor(playerTank, acceptanceRadius);

		controlledTank->AimAt(playerTank->GetActorLocation());

		controlledTank->Fire(); // limit firing speed
	}
	
}