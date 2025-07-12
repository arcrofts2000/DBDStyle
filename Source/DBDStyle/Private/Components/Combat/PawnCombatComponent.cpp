// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/PawnCombatComponent.h"

void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag WeaponTagToRegister, ADBDItemBase* WeaponToRegister, bool bRegisterAsEquippedWeapon)
{

}

void UPawnCombatComponent::K2_RegisterSpawnedWeapon(FGameplayTag WeaponTagToRegister, ADBDItemBase* WeaponToRegister, bool bRegisterAsEquippedWeapon)
{
	RegisterSpawnedWeapon(WeaponTagToRegister, WeaponToRegister, bRegisterAsEquippedWeapon);
}