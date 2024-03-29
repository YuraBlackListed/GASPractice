// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "GASPractice/GASPractice.h"
#include "ThirdPersonCharacterBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterDiedDelegate, AThirdPersonCharacterBase*, character);


UCLASS()
class GASPRACTICE_API AThirdPersonCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:


	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	// Sets default values for this character's properties
	AThirdPersonCharacterBase(const class FObjectInitializer& Object);

	UPROPERTY(BlueprintAssignable, Category = "GASPractice|Character")
	FCharacterDiedDelegate OnCharacterDied;

	UFUNCTION(BlueprintCallable, Category = "GASPractice|Character")
	virtual bool IsAlive() const;

	UFUNCTION(BlueprintCallable, Category = "GASPractice|Character")
	virtual int32 GetAbilityLevel(GASAbilityID AbilityID) const;
	
	virtual void RemoveCharacterAbilities();

	virtual void Die();

	UFUNCTION(BlueprintCallable, Category = "GASPractice|Character")
	virtual void FinishDying();

	UFUNCTION(BlueprintCallable, Category = "GASPractice|Character|Attributes")
	float GetCharacterLevel() const;
	
	UFUNCTION(BlueprintCallable, Category = "GASPractice|Character|Attributes")
	float GetHealth() const;

	UFUNCTION(BlueprintCallable, Category = "GASPractice|Character|Attributes")
	float GetMaxHealth() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	TWeakObjectPtr<class UCharacterAbilitySystemComponent> AbilitySystemComponent;
	TWeakObjectPtr<class UCharacterAttributeSetBase> AttributeSetBase;

	FGameplayTag DeadTag;
	FGameplayTag EffectRemoveOnDeathTag;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "GASPractice|Character")
	FText CharacterName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GASPractice|Animation")
	UAnimMontage* DeathMontage;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "GASPractice|Abilities")
	TArray<TSubclassOf<class UCharacterGameplayAbility>> CharacterAbilities;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "GASPractice|Abilities")
	TSubclassOf<class UGameplayEffect> DefaultAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "GASPractice|Abilities")
	TArray<TSubclassOf<class UGameplayEffect>> StartupEffects;

	virtual void AddCharacterAbilities();

	virtual void InitializeAttributes();
	
	virtual void AddStartupEffects();

	virtual void SetHealth(float Health);


};
