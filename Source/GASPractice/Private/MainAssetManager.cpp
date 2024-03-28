// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAssetManager.h"
#include "AbilitySystemGlobals.h"

void UMainAssetManager::StartInitialLoading() 
{
	Super::StartInitialLoading();
	UAbilitySystemGlobals::Get().InitGlobalData();
	UE_LOG(LogTemp, Warning, TEXT("Hello World!"));
}