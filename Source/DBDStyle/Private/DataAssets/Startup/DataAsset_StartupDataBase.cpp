// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/Startup/DataAsset_StartupDataBase.h"
#include "AbilitySystem/DBDAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/DBDGameplayAbility.h"

void UDataAsset_StartupDataBase::GiveToAbilitySystemComponent(UDBDAbilitySystemComponent* ASCToGive, int32 ApplyLevel)
{
	check(ASCToGive);

	GrantAbilities(ActivateOnGivenAbilities, ASCToGive, ApplyLevel);
	GrantAbilities(ReactiveAbilities, ASCToGive, ApplyLevel);
}

void UDataAsset_StartupDataBase::GrantAbilities(const TArray<TSubclassOf<UDBDGameplayAbility>>& AbilitiesToGive, UDBDAbilitySystemComponent* ASCToGive, 
	int32 ApplyLevel)
{
	if (AbilitiesToGive.IsEmpty())
		return;

	for (const TSubclassOf<UDBDGameplayAbility>& Ability : AbilitiesToGive)
	{
		if (!Ability) continue;

		FGameplayAbilitySpec Spec(Ability);
		Spec.SourceObject = ASCToGive->GetAvatarActor();
		Spec.Level = ApplyLevel;

		ASCToGive->GiveAbility(Spec);
	}
}