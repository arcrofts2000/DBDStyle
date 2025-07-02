// Attempt at recreating Dead By Daylight for Adam Crofts's Portfolio


#include "Characters/DBDKillerBase.h"
#include "Camera/CameraComponent.h"
#include "Components/SpotLightComponent.h"
#include "AbilitySystem/DBDAbilitySystemComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/Input/DBDInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "InputActionValue.h"
#include "DBDGameplayTags.h"
#include "DrawDebugHelpers.h"


ADBDKillerBase::ADBDKillerBase()
{
	/* Sockets defined here to prevent renaming and potential breaking */
	HeadSocketName = "head";
	RightHandSocketName = "righthand";

	PrimaryActorTick.bCanEverTick = true;

	/* Create First Person Mesh and set up ready for use in game with Primitive Types */
	FirstPersonMesh = CreateDefaultSubobject<USkeletalMeshComponent>("First Person Mesh");
	FirstPersonMesh->SetupAttachment(GetRootComponent());
	FirstPersonMesh->SetOnlyOwnerSee(true);
	FirstPersonMesh->SetFirstPersonPrimitiveType(EFirstPersonPrimitiveType::FirstPerson);
	FirstPersonMesh->SetCollisionProfileName("No Collision");

	/* Attach Camera to head socket using socket name defined at top of constructor */
	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>("First Person Camera");
	FirstPersonCamera->SetupAttachment(GetFirstPersonMesh(), HeadSocketName);
	FirstPersonCamera->SetEnableFirstPersonFieldOfView(true);
	FirstPersonCamera->SetEnableFirstPersonScale(true);
	FirstPersonCamera->SetFirstPersonFieldOfView(60.f);
	FirstPersonCamera->SetFirstPersonScale(0.6f);
	FirstPersonCamera->bUsePawnControlRotation = true;

	/* Make it so the Third Person Mesh is invisible to owner and prevent collisions using FirstPersonPrimitiveType */
	GetMesh()->SetOwnerNoSee(true);
	GetMesh()->SetFirstPersonPrimitiveType(EFirstPersonPrimitiveType::WorldSpaceRepresentation);
	GetMesh()->SetCollisionProfileName("No Collision");

	KillerAuraLight = CreateDefaultSubobject<USpotLightComponent>("Killer Aura Light");
	KillerAuraLight->SetupAttachment(GetRootComponent());
}

//~ Begin APawn Interface
void ADBDKillerBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (AbilitySystemComp && Attributes)
	{
		const FString ASCText = FString::Printf(TEXT("Owner Actor: %s, Avatar Actor: %s"),
			*AbilitySystemComp->GetOwner()->GetActorLabel(), *AbilitySystemComp->GetAvatarActor()->GetActorLabel());
		GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Red, ASCText);
		GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Red, "AttributeSet Valid!");
	}
}
//~ End APawn Interface

void ADBDKillerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADBDKillerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADBDKillerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	const APlayerController* PC = GetController<APlayerController>();
	const ULocalPlayer* LP = PC->GetLocalPlayer();

	/* Cast the current Subsystem to EnhancedInput Subsystem and check incase of crashes */
	UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);

	/* If the Subsystem is fine, clear all current mappings (if any) and create a new one */
	/* This could also be done in the Player Controller instead, though this won't have respawning so unnecessary */
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);

	UDBDInputComponent* InputComp = CastChecked<UDBDInputComponent>(PlayerInputComponent);

	InputComp->BindNativeInputAction(InputConfigDataAsset, DBDGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &ADBDKillerBase::MoveInput);
	InputComp->BindNativeInputAction(InputConfigDataAsset, DBDGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this, &ADBDKillerBase::LookInput);
	InputComp->BindNativeInputAction(InputConfigDataAsset, DBDGameplayTags::InputTag_Killer_PrimaryAttack, ETriggerEvent::Started, this, &ADBDKillerBase::PrimaryAttackInput);
	InputComp->BindNativeInputAction(InputConfigDataAsset, DBDGameplayTags::InputTag_Killer_SecondaryAttack, ETriggerEvent::Started, this, &ADBDKillerBase::SecondaryAttackInput);
}



/** Input Functions **/
void ADBDKillerBase::MoveInput(const FInputActionValue& InputValue)
{
	FVector2D Value = InputValue.Get<FVector2D>();
	TryToMove(Value.X, Value.Y);
}

void ADBDKillerBase::LookInput(const FInputActionValue& InputValue)
{
	FVector2D Value = InputValue.Get<FVector2D>();
	TryToLook(Value.X, Value.Y);
}

void ADBDKillerBase::PrimaryAttackInput()
{
	TryPrimaryAttack();
}

void ADBDKillerBase::SecondaryAttackInput()
{
	TrySecondaryAttack();
}



/**  **/
void ADBDKillerBase::TryToMove(const float x, const float y)
{
	AddMovementInput(GetActorForwardVector(), y);
	AddMovementInput(GetActorRightVector(), x);
}

void ADBDKillerBase::TryToLook(const float x, const float y)
{
	AddControllerYawInput(x);
	AddControllerPitchInput(y);
}

//void ADBDKillerBase::TryPrimaryAttack()
//{
//
//}
//
//void ADBDKillerBase::TrySecondaryAttack()
//{
//
//}