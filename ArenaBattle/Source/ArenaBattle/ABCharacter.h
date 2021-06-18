// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ABCharacter.generated.h"

UCLASS()
class ARENABATTLE_API AABCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AABCharacter();

protected:
	enum class EControlMode
	{
		GTA,
		DIABLO,
		END,
	};

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SetContorlMode(EControlMode eControlMode);
	EControlMode CurrentControlMode = EControlMode::GTA;
	FVector DirectionToMove = FVector::ZeroVector;

	float ArmLengthTo = 0.0f;
	FRotator ArmRotationTo = FRotator::ZeroRotator;
	float ArmLengthSpeed = 0.0f;
	float ArmRotationSpeed = 0.0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PostInitializeComponents() override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	bool CanSetWeapon();
	void SetWeapon(class AABWeapon* NewWeapon);


	UPROPERTY(VisibleAnyWhere, Category = Camera)
		USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnyWhere, Category = Camera)
		UCameraComponent* Camera;

	UPROPERTY(VisibleAnyWhere, Category = Weapon)
		USkeletalMeshComponent* Weapon;

	UPROPERTY(VisibleAnyWhere, Category = Weapon)
		class AABWeapon* CurrentWeapon;

	UPROPERTY(VisibleAnyWhere, Category = Stat)
		class UABCharacterStatComponent* CharacterStat;

private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);
	void Turn(float NewAxisValue);
	void LookUp(float NewAxisValue);
	void ViewChange();
	void Attack();
	void AttackStartComboState();
	void AttackEndComboState();
	void AttackCheck();
	
	UFUNCTION()
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

protected:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAcess = true))
		bool CanNextCombo;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAcess = true))
		bool IsComboInputOn;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAcess = true))
		int32 CurrentCombo;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAcess = true))
		int32 MaxCombo;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAcess = true))
		bool IsAttacking;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAcess = true))
		float AttackRange;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAcess = true))
		float AttackRadius;

	UPROPERTY()
		class UABAnimInstance* ABAnim;
};
