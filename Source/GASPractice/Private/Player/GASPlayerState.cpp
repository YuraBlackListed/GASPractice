// Fill out your copyright notice in the Description page of Project Settings.
// Fill out your copyright notice in the Description page of Project Settings.
// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/GASPlayerState.h"
#include "Character/Abilities/AttributeSets/CharacterAttributeSetBase.h"
#include "Character/Abilities/CharacterAbilitySystemComponent.h"

AGASPlayerState::AGASPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UCharacterAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSetBase = CreateDefaultSubobject<UCharacterAttributeSetBase>(TEXT("AttributeSetBase"));

	//default one in playerstates is too low and may work bad with GAS
	NetUpdateFrequency = 100.0f;

	DeadTag = FGameplayTag::RequestGameplayTag(FName("State.Dead"));
}

UAbilitySystemComponent* AGASPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UCharacterAttributeSetBase* AGASPlayerState::GetAttributeSetBase() const
{
	return AttributeSetBase;
}

bool AGASPlayerState::IsAlive() const
{
	return GetHealth() > 0.0f;
}

void AGASPlayerState::ShowAbilityConfirmCancelText(bool ShowText)
{
	//TODO -- HUD later
}

float AGASPlayerState::GetHealth() const
{
	return AttributeSetBase->GetHealth();
}

float AGASPlayerState::GetMaxHealth() const
{
	return AttributeSetBase->GetMaxHealth();
}

int32 AGASPlayerState::GetCharacterLevel() const
{
	return AttributeSetBase->GetLevel();
}

void AGASPlayerState::BeginPlay()
{
	Super::BeginPlay();

	if (AbilitySystemComponent)
	{
		HealthChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetBase->GetHealthAttribute()).AddUObject(this, &AGASPlayerState::HealthChanged);
		MaxHealthChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetBase->GetMaxHealthAttribute()).AddUObject(this, &AGASPlayerState::MaxHealthChanged);
		CharacterLevelChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetBase->GetLevelAttribute()).AddUObject(this, &AGASPlayerState::CharacterLevelChanged);
	}

	AbilitySystemComponent->RegisterGameplayTagEvent(FGameplayTag::RequestGameplayTag(FName("State.Debuff.Stun")), EGameplayTagEventType::NewOrRemoved).AddUObject(this, &AGASPlayerState::StunTagChanged);
}
void AGASPlayerState::HealthChanged(const FOnAttributeChangeData& Data)
{
	UE_LOG(LogTemp, Warning, TEXT("Health Changed!"));
}

void AGASPlayerState::MaxHealthChanged(const FOnAttributeChangeData& Data)
{
	UE_LOG(LogTemp, Warning, TEXT("Max Health Changed!"));
}

void AGASPlayerState::CharacterLevelChanged(const FOnAttributeChangeData& Data)
{
	UE_LOG(LogTemp, Warning, TEXT("Character Level Changed!"));
}

void AGASPlayerState::StunTagChanged(const FGameplayTag CallbackTag, int32 NewCount)
{
	if(NewCount > 0)
	{
		FGameplayTagContainer AbilityTagsToCancel;
		AbilityTagsToCancel.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability")));

		FGameplayTagContainer AbilityTagsToIgnore;
		AbilityTagsToCancel.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability.NotCanceledByStun")));

		AbilitySystemComponent->CancelAbilities(&AbilityTagsToCancel, &AbilityTagsToIgnore);
	}
}
