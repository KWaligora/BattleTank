// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		//UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank"));
	}
	else {
		//UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) { return nullptr; }
	return Cast<ATank>(PlayerTank);
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}