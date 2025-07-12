// Attempt at recreating Dead By Daylight for Adam Crofts's Portfolio


#include "Characters/DBDCharacterBase.h"
#include "AbilitySystem/DBDAbilitySystemComponent.h"
#include "AbilitySystem/DBDAttributeSet.h"
#include "DataAssets/Startup/DataAsset_StartupDataBase.h"


ADBDCharacterBase::ADBDCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComp = CreateDefaultSubobject<UDBDAbilitySystemComponent>("Ability System Comp");

	Attributes = CreateDefaultSubobject<UDBDAttributeSet>("Attributes");
}

UAbilitySystemComponent* ADBDCharacterBase::GetAbilitySystemComponent() const
{
	return GetAbilitySystemComp();
}

//~ Begin APawn Interface
void ADBDCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (AbilitySystemComp)
	{
		AbilitySystemComp->InitAbilityActorInfo(this, this);
	}

	ensureMsgf(!StartupData.IsNull(), TEXT("Forgot to assign Startup Data to %s"), *GetName());

	if (!StartupData.IsNull())
	{
		if (UDataAsset_StartupDataBase* LoadedData = StartupData.LoadSynchronous())
			LoadedData->GiveToAbilitySystemComponent(AbilitySystemComp);
	}
}
//~ End APawn Interface


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

