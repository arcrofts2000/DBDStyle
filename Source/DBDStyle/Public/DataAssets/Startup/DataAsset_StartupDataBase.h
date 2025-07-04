// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartupDataBase.generated.h"

class UDBDGameplayAbility;
class UDBDAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class DBDSTYLE_API UDataAsset_StartupDataBase : public UDataAsset
{
	GENERATED_BODY()
	
public:
	virtual void GiveToAbilitySystemComponent(UDBDAbilitySystemComponent* ASCToGive, int32 ApplyLevel = 1);


protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartupData")
	TArray<TSubclassOf<UDBDGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartupData")
	TArray<TSubclassOf<UDBDGameplayAbility>> ReactiveAbilities;


	void GrantAbilities(const TArray<TSubclassOf<UDBDGameplayAbility>>& AbilitiesToGive, UDBDAbilitySystemComponent* ASCToGive, int32 ApplyLevel = 1);
};
