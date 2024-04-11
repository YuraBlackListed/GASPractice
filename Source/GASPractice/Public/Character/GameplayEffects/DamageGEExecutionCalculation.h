// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "NativeGameplayTags.h"
#include "DamageGEExecutionCalculation.generated.h"

UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_CALCULATION_DAMAGE);
/**
 * 
 */
UCLASS()
class GASPRACTICE_API UDamageGEExecutionCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
	
public:
	UDamageGEExecutionCalculation();

	float CalculateDamage(const float Damage, const float Armor) const;

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
