// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/DBDGameplayAbility.h"
#include "AbilitySystem/DBDAbilitySystemComponent.h"
#include "Characters/DBDKillerBase.h"
#include "Characters/DBDSurvivorBase.h"

//~ Begin UGameplayAbility Interface
void UDBDGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	if (ActivationPolicy == EDBDAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo && !Spec.IsActive())
		{
			ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
		}
	}
}

void UDBDGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, 
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if (ActivationPolicy == EDBDAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo)
		{
			ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
		}
	}
}
//~ End UGameplayAbility Interface

USkeletalMeshComponent* UDBDGameplayAbility::GetKillerFirstPersonMesh() const
{
	if (ADBDKillerBase* OwningCharacter = Cast<ADBDKillerBase>(CurrentActorInfo->OwnerActor.Get()))
	{
		return OwningCharacter->GetFirstPersonMesh();
	}

	return nullptr;
}

USkeletalMeshComponent* UDBDGameplayAbility::GetActorThirdPersonMesh() const
{
	if (ADBDCharacterBase* OwningCharacter = Cast<ADBDCharacterBase>(CurrentActorInfo->OwnerActor.Get()))
	{
		return OwningCharacter->GetMesh();
	}

	return nullptr;
}

UCameraComponent* UDBDGameplayAbility::GetKillerCam() const
{
	if (ADBDKillerBase* OwningCharacter = Cast<ADBDKillerBase>(CurrentActorInfo->OwnerActor.Get()))
	{
		return OwningCharacter->GetFirstPersonCamera();
	}

	return nullptr;
}

UCameraComponent* UDBDGameplayAbility::GetSurvivorCam() const
{
	if (ADBDSurvivorBase* OwningCharacter = Cast<ADBDSurvivorBase>(CurrentActorInfo->OwnerActor.Get()))
	{
		return OwningCharacter->GetThirdPersonCamera();
	}

	return nullptr;
}

bool UDBDGameplayAbility::IsKiller() const
{
	return Cast<ADBDKillerBase>(CurrentActorInfo->OwnerActor.Get()) ? true : false;
}