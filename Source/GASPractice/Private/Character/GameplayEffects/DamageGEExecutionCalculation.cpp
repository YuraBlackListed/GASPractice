// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/GameplayEffects/DamageGEExecutionCalculation.h"
#include "Character/Abilities/AttributeSets/CustomAttributeSet.h"

UE_DEFINE_GAMEPLAY_TAG(TAG_CALCULATION_DAMAGE, "Calculation.Damage");

struct FDamageStatistics
{
	FGameplayEffectAttributeCaptureDefinition DefenceDefinition;

	FDamageStatistics()
	{
		DefenceDefinition = FGameplayEffectAttributeCaptureDefinition(UCustomAttributeSet::GetArmorAttribute(), EGameplayEffectAttributeCaptureSource::Target, true);
	}
};

static FDamageStatistics GetStatistics()
{
	static FDamageStatistics DamageStatistics;

	return DamageStatistics;
};

UDamageGEExecutionCalculation::UDamageGEExecutionCalculation()
{
	RelevantAttributesToCapture.Add(GetStatistics().DefenceDefinition);
}

float UDamageGEExecutionCalculation::CalculateDamage(const float Damage, const float Armor) const
{
	return Damage-Armor;
}

void UDamageGEExecutionCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();
	float Armor = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetStatistics().DefenceDefinition, FAggregatorEvaluateParameters(), Armor);
	const float Damage = Spec.GetSetByCallerMagnitude(TAG_CALCULATION_DAMAGE, true, 0.0f);
	const float CalculatedDamage = -CalculateDamage(Damage, Armor);
	OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(UCustomAttributeSet::GetHealthAttribute(), EGameplayModOp::Additive, CalculatedDamage));
}
