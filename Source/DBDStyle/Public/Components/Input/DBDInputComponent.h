// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "InputActionValue.h"
#include "DBDInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class DBDSTYLE_API UDBDInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
	
public:
	template<class UserObject, typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InConfig, const FGameplayTag& InTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func);
};

template<class UserObject, typename CallbackFunc>
inline void UDBDInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InConfig, const FGameplayTag& InTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	checkf(InConfig, TEXT("Input Config Data Asset is null! Cannot bind Input Action."));

	if (UInputAction* FoundAction = InConfig->FindNativeInputActionByTag(InTag))
	{
		BindAction(FoundAction, TriggerEvent, ContextObject, Func);
	}
}