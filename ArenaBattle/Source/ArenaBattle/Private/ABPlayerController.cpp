// Fill out your copyright notice in the Description page of Project Settings.

#include "ABPlayerController.h"
#include "ABCharacterStatComponent.h"
#include "ABCharacter.h"

void AABPlayerController::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	ABLOG_S(Warning);
}

void AABPlayerController::Possess(APawn * aPawn)
{
	ABLOG_S(Warning);
	Super::Possess(aPawn);
	Cast<AABCharacter>(aPawn)->CharacterStat->SetNewLevel(10);
}

void AABPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	//InputComponent->BindAxis(TEXT("LEFTRIGHT"), this, &AABPlayerController::LeftRight);
}

void AABPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
}

void AABPlayerController::LeftRight(float NewAxisValue)
{
}
