// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Abilities/AttributeSets/CustomAttributeSet.h"
#include "AbilitySystemComponent.h"

UCustomAttributeSet::UCustomAttributeSet()
{
	InitDamage(0.0f);
	InitSpeed(600.0f);
	InitBullets(10.0f);
	InitMaxBullets(100.0f);
}
void UCustomAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	if (Attribute == GetBulletsAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, GetMaxBullets());
	}
}