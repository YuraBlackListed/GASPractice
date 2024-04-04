
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

	UPROPERTY(BlueprintReadOnly, Category = "Speed")
	FGameplayAttributeData Speed;

	UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData Damage;


	ATTRIBUTE_ACCESSORS(UCustomAttributeSet, Health)
	ATTRIBUTE_ACCESSORS(UCustomAttributeSet, MaxHealth)
	ATTRIBUTE_ACCESSORS(UCustomAttributeSet, Speed)
	ATTRIBUTE_ACCESSORS(UCustomAttributeSet, Damage)

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
};
