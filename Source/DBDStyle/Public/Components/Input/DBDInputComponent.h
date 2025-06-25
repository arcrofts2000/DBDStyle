// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
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
	void BindNativeInputAction(const UDataAsset_InputConfig* InputConfig, const FGameplayTag& InTag,
		ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func);
};

template<class UserObject, typename CallbackFunc>
void BindNativeInputAction(const UDataAsset_InputConfig* InputConfig, const FGameplayTag& InTag,
	ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	checkf(InputConfig, TEXT("Input Config Data Asset is null! Cannot bind Input Action."));

	if (UInputAction* FoundAction = InputConfig->FindNativeInputActionByTag(InTag))
	{
		BindAction(FoundAction, TriggerEvent, ContextObject, Func);
	}
}