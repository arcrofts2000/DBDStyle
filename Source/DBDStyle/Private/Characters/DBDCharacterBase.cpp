// Attempt at recreating Dead By Daylight for Adam Crofts's Portfolio


#include "Characters/DBDCharacterBase.h"


ADBDCharacterBase::ADBDCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

}


void ADBDCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}


void ADBDCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ADBDCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

