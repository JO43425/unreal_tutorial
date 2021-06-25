// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "EngineMinimal.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Foutain.generated.h"

UCLASS()
class ARENABATTLE_API AFoutain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFoutain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void PostInitializeComponents() override;

public:

	UPROPERTY(VisibleAnyWhere)
	UStaticMeshComponent* Body;

	UPROPERTY(VisibleAnyWhere)
	UStaticMeshComponent* Water;

	UPROPERTY(VisibleAnyWhere)
	UPointLightComponent* Light;

	UPROPERTY(VisibleAnyWhere)
	UParticleSystemComponent* Splash;

	UPROPERTY(VisibleAnyWhere)
	URotatingMovementComponent* Movement;

	UPROPERTY(EditAnyWhere, Category=ID)
	int32 ID;

private:
	UPROPERTY(EditAnyWhere, Category = Stat, Meta = (AllowPrivateAcess = true))
	float RotateSpeed;
	
};
