// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ABPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API AABPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	AABPlayerController();

	virtual void PostInitializeComponents() override;
	virtual void Possess(APawn* aPawn) override;

	class UABHudWidget* GetHUDWidget() const;
	void NPCKill(class AABCharacter* KilledNpc) const;
	void AddGameScore() const;
protected:
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
		TSubclassOf<class UABHudWidget> HUDWidgetClass;
private:
	void LeftRight(float NewAxisValue);
	
	UPROPERTY()
		class UABHudWidget* HUDWidget;
	UPROPERTY()
		class AABPlayerState* ABPlayerState;
};
