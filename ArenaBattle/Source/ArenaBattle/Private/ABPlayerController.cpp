// Fill out your copyright notice in the Description page of Project Settings.

#include "ABPlayerController.h"
#include "ABHudWidget.h"
#include "ABCharacterStatComponent.h"
#include "ABCharacter.h"
#include "ABPlayerState.h"

AABPlayerController::AABPlayerController()
{
	static ConstructorHelpers::FClassFinder<UABHudWidget> UI_HUD_C(TEXT("/Game/UI/UI_HUD"));

	if (UI_HUD_C.Succeeded())
	{
		HUDWidgetClass = UI_HUD_C.Class;
	}
}

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

UABHudWidget * AABPlayerController::GetHUDWidget() const
{
	return HUDWidget;
}

void AABPlayerController::NPCKill(AABCharacter * KilledNpc) const
{
	ABPlayerState->AddExp(KilledNpc->GetExp());
}

void AABPlayerController::AddGameScore() const
{
	ABPlayerState->AddGameScore();
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

	HUDWidget = CreateWidget<UABHudWidget>(this, HUDWidgetClass);
	HUDWidget->AddToViewport();

	ABPlayerState = Cast<AABPlayerState>(PlayerState);
	ABCHECK(nullptr != ABPlayerState);
	HUDWidget->BindPlayerState(ABPlayerState);
	ABPlayerState->OnPlayerStateChanged.Broadcast();
}

void AABPlayerController::LeftRight(float NewAxisValue)
{
}
