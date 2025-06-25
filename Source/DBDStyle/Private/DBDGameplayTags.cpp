// Attempt at recreating Dead By Daylight for Adam Crofts's Portfolio


#include "DBDGameplayTags.h"

namespace DBDGameplayTags
{
	/** Input Tags **/
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");

	/** Killer Specific Inputs **/
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Killer_PrimaryAttack, "InputTag.Killer.PrimaryAttack");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Killer_SecondaryAttack, "InputTag.Killer.SecondaryAttack");

	/** Survivor Specific Inputs **/
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Survivor_Interact, "InputTag.Survivor.Interact");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Survivor_Use, "InputTag.Survivor.Use");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Survivor_Sprint, "InputTag.Survivor.Sprint");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Survivor_Crouch, "InputTag.Survivor.Crouch");
}