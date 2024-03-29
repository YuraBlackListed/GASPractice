// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "Character/Abilities/AttributeSets/CharacterAttributeSetBase.h"
#include "GASPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class GASPRACTICE_API AGASPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	AGASPlayerState();

	class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	class UCharacterAttributeSetBase* GetAttributeSetBase() const;

	UFUNCTION(BlueprintCallable, Category = "GASPractice|GASPlayerState")
	bool IsAlive() const;

	UFUNCTION(BlueprintCallable, Category = "GASPractice|GASPlayerState|Attributes")
	void ShowAbilityConfirmCancelText(bool ShowText);

	UFUNCTION(BlueprintCallable, Category = "GASPractice|GASPlayerState|Attributes")
	float GetHealth() const;

	UFUNCTION(BlueprintCallable, Category = "GASPractice|GASPlayerState|Attributes")
	float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable, Category = "GASPractice|GASPlayerState|Attributes")
	int32 GetCharacterLevel() const;

protected:
	UPROPERTY()
	class UCharacterAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	class UCharacterAttributeSetBase* AttributeSetBase;

	FGameplayTag DeadTag;

	FDelegateHandle HealthChangedDelegateHandle;
	FDelegateHandle MaxHealthChangedDelegateHandle;
	FDelegateHandle CharacterLevelChangedDelegateHandle;

	virtual void BeginPlay() override;

	virtual void HealthChanged(const FOnAttributeChangeData& Data);
	virtual void MaxHealthChanged(const FOnAttributeChangeData& Data);
	virtual void CharacterLevelChanged(const FOnAttributeChangeData& Data);

	virtual void StunTagChanged(const FGameplayTag CallbackTag, int32 NewCount);
};
