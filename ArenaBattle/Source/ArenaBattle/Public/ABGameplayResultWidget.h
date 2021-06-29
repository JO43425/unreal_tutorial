// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ABGameplayResultWidget.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABGameplayResultWidget : public UUserWidget
{
	GENERATED_BODY()
	
	
public:
	void BindGameState(class AABGameStateBase* GameState);

	UFUNCTION()
		void OnResturnToTitleClicked();
	UFUNCTION()
		void OnRetryGameClicked();

protected:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY()
		class UButton* ReturnToTitleButton;

	UPROPERTY()
		class UButton* RetryGameButton;

private:
	TWeakObjectPtr<class AABGameStateBase> CurrentGameState;

	
};
