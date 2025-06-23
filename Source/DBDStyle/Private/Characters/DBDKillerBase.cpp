// Attempt at recreating Dead By Daylight for Adam Crofts's Portfolio


#include "Characters/DBDKillerBase.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"


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
}

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
	Subsystem->AddMappingContext(DefaultIMC, 0);

	/* Cast InputComponent to Enhanced, and Bind Actions */
	UEnhancedInputComponent* InputComp = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	InputComp->BindAction(Input_Move, ETriggerEvent::Triggered, this, &ADBDKillerBase::MoveInput);
	InputComp->BindAction(Input_Look, ETriggerEvent::Triggered, this, &ADBDKillerBase::LookInput);
	InputComp->BindAction(Input_PrimaryAttack, ETriggerEvent::Started, this, &ADBDKillerBase::PrimaryAttackInput);
	InputComp->BindAction(Input_SecondaryAttack, ETriggerEvent::Started, this, &ADBDKillerBase::SecondaryAttackInput);
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