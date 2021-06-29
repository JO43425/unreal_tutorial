// Fill out your copyright notice in the Description page of Project Settings.

#include "ABGameMode.h"
#include "ABPawn.h"
#include "ABCharacter.h"
#include "ABPlayerController.h"
#include "ABPlayerState.h"
#include "ABGameStateBase.h"




AABGameMode::AABGameMode()
{
	DefaultPawnClass = AABCharacter::StaticClass();
	PlayerControllerClass = AABPlayerController::StaticClass();	
	PlayerStateClass = AABPlayerState::StaticClass();
	GameStateClass = AABGameStateBase::StaticClass();
	/*
	static ConstructorHelpers::FClassFinder<APawn> BP_PAWN_C(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (BP_PAWN_C.Succeeded())
	{
		DefaultPawnClass = BP_PAWN_C.Class;
	}
	*/
}

void AABGameMode::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	ABGameState = Cast<AABGameStateBase>(GameState);
}

void AABGameMode::PostLogin(APlayerController * NewPlayer)
{
	Super::PostLogin(NewPlayer);

	auto ABPlayerState = Cast<AABPlayerState>(NewPlayer->PlayerState);
	ABCHECK(nullptr != ABPlayerState);
	ABPlayerState->InitPlayerData();
}

void AABGameMode::AddScore(AABPlayerController* ScoredPlayer)
{
	for (FConstPlayerControllerIterator iter = GetWorld()->GetPlayerControllerIterator(); iter; ++iter)
	{
		const auto ABPlayerController = Cast<AABPlayerController>(iter->Get());
		if ((nullptr != ABPlayerController) && (ScoredPlayer == ABPlayerController))
		{
			ABPlayerController->AddGameScore();
			break;
		}
	}

	ABGameState->AddGameScore();
}
