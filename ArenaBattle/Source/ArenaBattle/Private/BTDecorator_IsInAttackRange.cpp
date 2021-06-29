// Fill out your copyright notice in the Description page of Project Settings.

#include "BTDecorator_IsInAttackRange.h"
#include "ABAIController.h"
#include "ABCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"



UBTDecorator_IsInAttackRange::UBTDecorator_IsInAttackRange()
{
	NodeName = TEXT("CanAttack");
}

bool UBTDecorator_IsInAttackRange::CalculateRawConditionValue(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory) const
{
	//�θ��Լ� ȣ��
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	//AI�� �����̴� Pawn ���
	auto ControllingPawn = Cast<AABCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == ControllingPawn)
		return false;

	//AI�� target�ϴ� ABCharacter ���
	auto Target = Cast<AABCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(AABAIController::TargetKey));
	if (nullptr == Target)
		return false;
	//�� ������Ʈ ������ �Ÿ��� 200�����̸� ���ݹ��� TRUE
	bResult = (Target->GetDistanceTo(ControllingPawn) <= ControllingPawn->GetFinalAttackRange());
	return bResult;
}
