// Attempt at recreating Dead By Daylight for Adam Crofts's Portfolio


#include "AnimInstances/DBDCharacterAnimInstance.h"
#include "Characters/DBDCharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"

void UDBDCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (OwningCharacter = Cast<ADBDCharacterBase>(TryGetPawnOwner()))
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void UDBDCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	if (!OwningCharacter || !OwningMovementComponent)
		return;

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;

	if (bHasAcceleration)
	{
		IdleElapsedTime = 0.f;
		bShouldEnterRelaxedState = false;
	}
	else
	{
		IdleElapsedTime += DeltaSeconds;
		bShouldEnterRelaxedState = IdleElapsedTime >= EnterRelaxedStateThreshold;
	}
}