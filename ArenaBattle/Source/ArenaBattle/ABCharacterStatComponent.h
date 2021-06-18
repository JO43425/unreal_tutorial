// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ABCharacterStatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARENABATTLE_API UABCharacterStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UABCharacterStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void InitializeComponent() override;

public:
	void SetNewValue(int32 NewLevel);
		
private:
	struct FABCharacterData* CurrentStatData = nullptr;
	UPROPERTY(EditInstanceOnly, Category = Stat, Meta = (AllowPrivateAcess = true))
		int32 Level;
	UPROPERTY(Translent, VisibleInstanceOnly, Category = Stat, Meta = (AllowPrivateAcess = true))
		float CurrentHP;
};
