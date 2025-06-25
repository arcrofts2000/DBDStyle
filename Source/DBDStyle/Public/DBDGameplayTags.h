// Attempt at recreating Dead By Daylight for Adam Crofts's Portfolio

#pragma once
#include "NativeGameplayTags.h"

namespace DBDGameplayTags
{
	/** Input Tags **/
	DBDSTYLE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	DBDSTYLE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);

	/** Killer Specific Inputs **/
	DBDSTYLE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Killer_PrimaryAttack);
	DBDSTYLE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Killer_SecondaryAttack);
	
	/** Survivor Specific Inputs **/
	DBDSTYLE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Survivor_Interact);
	DBDSTYLE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Survivor_Use);
	DBDSTYLE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Survivor_Sprint);
	DBDSTYLE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Survivor_Crouch);
}