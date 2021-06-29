// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ABHudWidget.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABHudWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void BindCharacterStat(class UABCharacterStatComponent* CharacterStat);
	void BindPlayerState(class AABPlayerState* PlayerState);

protected:
	virtual void NativeConstruct() override;
	void UpdateChracterStat();
	void UpdatePlayerState();

private:
	TWeakObjectPtr<class UABCharacterStatComponent> CurrentCharacterStat;
	TWeakObjectPtr<class AABPlayerState> CurrentPlayerState;

	UPROPERTY()
		class UProgressBar* HPBar;

	UPROPERTY()
		class UProgressBar* ExpBar;
	
	UPROPERTY()
		class UTextBlock* PlayerName;

	UPROPERTY()
		class UTextBlock* PlayerLevel;

	UPROPERTY()
		class UTextBlock* CurrentScore;

	UPROPERTY()
		class UTextBlock* HighScore;
	
};
