// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"


UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	float acceptanceRadius = 5000; // how close the AI is allowed to get to the player

public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
};
