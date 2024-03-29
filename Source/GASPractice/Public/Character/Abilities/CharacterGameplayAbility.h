// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GASPractice/GASPractice.h"
#include "CharacterGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class GASPRACTICE_API UCharacterGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UCharacterGameplayAbility();

	UPROPERTY(BlueprintReadonly, EditAnywhere, Category = "Ability")
	GASAbilityID AbilityInputID = GASAbilityID::None;
	
	UPROPERTY(BlueprintReadonly, EditAnywhere, Category = "Ability")
	GASAbilityID AbilityID = GASAbilityID::None;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ability")
	bool ActivateAbilityOnGranted = false;

	virtual void OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
};
