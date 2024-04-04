// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Abilities/AttributeSets/CustomAttributeSet.h"

UCustomAttributeSet::UCustomAttributeSet()
{
	InitDamage(10.0f);
	InitHealth(100.0f);
	InitMaxHealth(100.0f);
}
void UCustomAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, GetMaxHealth());
	}
}