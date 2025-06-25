// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "InputAction.h"

UInputAction* UDataAsset_InputConfig::FindNativeInputActionByTag(const FGameplayTag& InTag) const
{
	for (const FDBDInputActionConfig& Config : NativeInputActions)
	{
		if (Config.InputTag == InTag && Config.InputAction)
			return Config.InputAction;
	}
	return nullptr;
}