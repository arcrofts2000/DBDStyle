// Attempt at recreating Dead By Daylight for Adam Crofts's Portfolio


#include "Characters/DBDSurvivorBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"

ADBDSurvivorBase::ADBDSurvivorBase()
{
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("Spring Arm Comp");
	SpringArmComp->SetupAttachment(GetRootComponent());
	SpringArmComp->TargetArmLength = 450.f;
	SpringArmComp->bUsePawnControlRotation = true;

	ThirdPersonCamera = CreateDefaultSubobject<UCameraComponent>("Third Person Camera");
	ThirdPersonCamera->SetupAttachment(SpringArmComp);
	ThirdPersonCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
}

void ADBDSurvivorBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADBDSurvivorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADBDSurvivorBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	const APlayerController* PC = GetController<APlayerController>();
	const ULocalPlayer* LP = PC->GetLocalPlayer();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);

	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(DefaultIMC, 0);

	UEnhancedInputComponent* InputComp = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	InputComp->BindAction(Input_Move, ETriggerEvent::Triggered, this, &ADBDSurvivorBase::MoveInput);
	InputComp->BindAction(Input_Look, ETriggerEvent::Triggered, this, &ADBDSurvivorBase::LookInput);
	InputComp->BindAction(Input_Crouch, ETriggerEvent::Started, this, &ADBDSurvivorBase::BeginCrouchInput);
	InputComp->BindAction(Input_Crouch, ETriggerEvent::Canceled, this, &ADBDSurvivorBase::EndCrouchInput);
	InputComp->BindAction(Input_Crouch, ETriggerEvent::Completed, this, &ADBDSurvivorBase::EndCrouchInput);
}

void ADBDSurvivorBase::MoveInput(const FInputActionValue& InputValue)
{
	FVector2D Value = InputValue.Get<FVector2D>();
	TryToMove(Value.X, Value.Y);
}

void ADBDSurvivorBase::LookInput(const FInputActionValue& InputValue)
{
	FVector2D Value = InputValue.Get<FVector2D>();
	TryToLook(Value.X, Value.Y);
}

void ADBDSurvivorBase::BeginCrouchInput()
{
	Crouch();
}

void ADBDSurvivorBase::EndCrouchInput()
{
	UnCrouch();
}



void ADBDSurvivorBase::TryToMove(const float x, const float y)
{
	AddMovementInput(GetActorForwardVector(), y);
	AddMovementInput(GetActorRightVector(), x);
}

void ADBDSurvivorBase::TryToLook(const float x, const float y)
{
	AddControllerYawInput(x);
	AddControllerPitchInput(y);
}