
#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CustomAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class GASPRACTICE_API UCustomAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UCustomAttributeSet();
	
	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData Health;

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData MaxHealth;

	UPROPERTY(BlueprintReadOnly, Category = "Armor")
		FGameplayAttributeData Armor;

	UPROPERTY(BlueprintReadOnly, Category = "Armor")
		FGameplayAttributeData MaxArmor;

	UPROPERTY(BlueprintReadOnly, Category = "Bullets")
	FGameplayAttributeData Bullets;

	UPROPERTY(BlueprintReadOnly, Category = "Bullets")
	FGameplayAttributeData MaxBullets;

	UPROPERTY(BlueprintReadOnly, Category = "Speed")
	FGameplayAttributeData Speed;

	ATTRIBUTE_ACCESSORS(UCustomAttributeSet, Health)
	ATTRIBUTE_ACCESSORS(UCustomAttributeSet, MaxHealth)
	ATTRIBUTE_ACCESSORS(UCustomAttributeSet, Armor)
	ATTRIBUTE_ACCESSORS(UCustomAttributeSet, MaxArmor)
	ATTRIBUTE_ACCESSORS(UCustomAttributeSet, Bullets)
	ATTRIBUTE_ACCESSORS(UCustomAttributeSet, MaxBullets)
	ATTRIBUTE_ACCESSORS(UCustomAttributeSet, Speed)

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};
