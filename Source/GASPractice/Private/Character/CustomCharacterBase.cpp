// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CustomCharacterBase.h"
#include "Character/Abilities/AttributeSets/CustomAttributeSet.h"
#include "Character/Abilities/CustomAbilitySystemComponent.h"

// Sets default values
ACustomCharacterBase::ACustomCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UCustomAbilitySystemComponent>("AbilitySystemComponent");
	AttributeSet = CreateDefaultSubobject<UCustomAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* ACustomCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
// Called when the game starts or when spawned
void ACustomCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

// Called every frame
void ACustomCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACustomCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

