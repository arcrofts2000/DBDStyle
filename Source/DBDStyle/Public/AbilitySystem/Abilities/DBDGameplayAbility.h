// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "DBDGameplayAbility.generated.h"

UENUM(BlueprintType)
enum class EDBDAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};


class USkeletalMeshComponent;
class UCameraComponent;

/**
 * 
 */
UCLASS()
class DBDSTYLE_API UDBDGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
protected:
	//~ Begin UGameplayAbility Interface
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;

	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, 
		const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	//~ End UGameplayAbility Interface

	UPROPERTY(EditDefaultsOnly, Category = "Ability")
	EDBDAbilityActivationPolicy ActivationPolicy = EDBDAbilityActivationPolicy::OnTriggered;

	USkeletalMeshComponent* GetKillerFirstPersonMesh() const;
	USkeletalMeshComponent* GetActorThirdPersonMesh() const;

	UCameraComponent* GetKillerCam() const;
	UCameraComponent* GetSurvivorCam() const;

	bool IsKiller() const;


public:
	/** Blueprint Pure Functions **/
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get First Person Mesh"))
	USkeletalMeshComponent* K2_GetKillerFirstPersonMesh() const { return GetKillerFirstPersonMesh(); }

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Third Person Mesh"))
	USkeletalMeshComponent* K2_GetActorThirdPersonMesh() const { return GetActorThirdPersonMesh(); }

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Killer Camera"))
	UCameraComponent* K2_GetKillerCam() const { return GetKillerCam(); }

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Survivor Camera"))
	UCameraComponent* K2_GetSurvivorCam() const { return GetSurvivorCam(); }

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Is Killer?"))
	bool K2_IsKiller() const { return IsKiller(); }
};
