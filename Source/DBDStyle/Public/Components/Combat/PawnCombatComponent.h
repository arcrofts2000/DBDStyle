// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/DBDPawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"
#include "PawnCombatComponent.generated.h"

class ADBDItemBase;

/**
 * 
 */
UCLASS()
class DBDSTYLE_API UPawnCombatComponent : public UDBDPawnExtensionComponentBase
{
	GENERATED_BODY()
	
private:
	TMap<FGameplayTag, TObjectPtr<ADBDItemBase>> CarriedItemMap;

public:
	void RegisterSpawnedWeapon(FGameplayTag WeaponTagToRegister, ADBDItemBase* WeaponToRegister, bool bRegisterAsEquipped = true);

	UFUNCTION(BlueprintCallable, Category = "DBD|Combat", meta = (DisplayName = "Register Spawned Weapon"))
	void K2_RegisterSpawnedWeapon(FGameplayTag WeaponTagToRegister, ADBDItemBase* WeaponToRegister, bool bRegisterAsEquipped = true);
};
