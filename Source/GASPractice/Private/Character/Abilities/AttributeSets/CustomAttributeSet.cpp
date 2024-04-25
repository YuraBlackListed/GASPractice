// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Abilities/AttributeSets/CustomAttributeSet.h"
#include "AbilitySystemComponent.h"

UCustomAttributeSet::UCustomAttributeSet()
{
	InitSpeed(600.0f);
	InitBullets(10.0f);
	InitMaxBullets(100.0f);
	InitHealth(60.0f);
	InitMaxHealth(100.0f);
	InitArmor(0.0f);
	InitMaxArmor(100.0f);
}
void UCustomAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
}
void UCustomAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	if (Attribute == GetBulletsAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, GetMaxBullets());
	}
	else if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, GetMaxHealth());
	}
	else if (Attribute == GetArmorAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, GetMaxArmor());
	}
}