// Fill out your copyright notice in the Description page of Project Settings.

#include "ABAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

const FName AABAIController::HomePosKey(TEXT("HomePos"));
const FName AABAIController::PatrolPosKey(TEXT("PatrolPos"));
const FName AABAIController::TargetKey(TEXT("Target"));

AABAIController::AABAIController()
{
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBObject(TEXT("/Game/AI/BB_ABCharacter"));
	if (BBObject.Succeeded())
	{
		BBAsset = BBObject.Object;
	}

	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTObject(TEXT("/Game/AI/BT_ABCharacter"));
	if (BTObject.Succeeded())
	{
		BTAsset = BTObject.Object;
	}
}

void AABAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

	/*
	if (UseBlackboard(BBAsset, Blackboard))
	{
		Blackboard->SetValueAsVector(HomePosKey, InPawn->GetActorLocation());
		if (!RunBehaviorTree(BTAsset))
		{
			ABLOG(Error, TEXT("AICOntroller couldn't run behavior tree!"));
		}
	}
	*/
}

void AABAIController::RunAI()
{
	if (UseBlackboard(BBAsset, Blackboard))
	{
		Blackboard->SetValueAsVector(HomePosKey, GetPawn()->GetActorLocation());
		if (!RunBehaviorTree(BTAsset))
		{
			ABLOG(Error, TEXT("AIController couldn't run behavior tree!"));
		}
	}
}

void AABAIController::StopAI()
{
	auto BehaviorTreeComponent = Cast<UBehaviorTreeComponent>(BrainComponent);
	if (nullptr != BehaviorTreeComponent)
	{
		BehaviorTreeComponent->StopTree(EBTStopMode::Safe);
	}
}

/*
AABAIController::AABAIController()
{
	RepeatInterval = 3.0f;
}

void AABAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);
	GetWorld()->GetTimerManager().SetTimer(RepeatTimerHandle, this, &AABAIController::OnRepeatTimer, 3.0f, true);
}

void AABAIController::UnPossess()
{
	Super::UnPossess();
	GetWorld()->GetTimerManager().ClearTimer(RepeatTimerHandle);
}

void AABAIController::OnRepeatTimer()
{
	auto CurrentPawn = GetPawn();
	ABCHECK(nullptr != CurrentPawn);

	UNavigationSystem* NavSystem = UNavigationSystem::GetNavigationSystem(GetWorld());
	if (nullptr == NavSystem) return;

	FNavLocation NextLocation;
	if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.0f, NextLocation))
	{
		UNavigationSystem::SimpleMoveToLocation(this, NextLocation.Location);
		ABLOG(Warning, TEXT("Next Location : %s"), *NextLocation.Location.ToString());
	}
}
*/
