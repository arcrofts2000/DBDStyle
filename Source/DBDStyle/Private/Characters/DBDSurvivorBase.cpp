// Attempt at recreating Dead By Daylight for Adam Crofts's Portfolio


#include "Characters/DBDSurvivorBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AbilitySystem/DBDAbilitySystemComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/Input/DBDInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "InputActionValue.h"
#include "DBDGameplayTags.h"

ADBDSurvivorBase::ADBDSurvivorBase()
{
	PrimaryActorTick.bCanEverTick = true;

	RightHandSocketName = "righthand";

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("Spring Arm Comp");
	SpringArmComp->SetupAttachment(GetRootComponent());
	SpringArmComp->TargetArmLength = 325.f;
	SpringArmComp->bUsePawnControlRotation = true;

	ThirdPersonCamera = CreateDefaultSubobject<UCameraComponent>("Third Person Camera");
	ThirdPersonCamera->SetupAttachment(SpringArmComp);
	ThirdPersonCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
}

//~ Begin APawn Interface
void ADBDSurvivorBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (AbilitySystemComp && Attributes)
	{
		const FString ASCText = FString::Printf(TEXT("Owner Actor: %s, Avatar Actor: %s"),
			*AbilitySystemComp->GetOwner()->GetActorLabel(), *AbilitySystemComp->GetAvatarActor()->GetActorLabel());
		GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Blue, ASCText);
		GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Blue, "AttributeSet Valid!");
	}
}
//~ End APawn Interface

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
	checkf(InputConfigDataAsset, TEXT("You have not assigned a valid Input Config Data Asset!"));

	const APlayerController* PC = GetController<APlayerController>();
	const ULocalPlayer* LP = PC->GetLocalPlayer();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);

	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);

	UDBDInputComponent* InputComp = Cast<UDBDInputComponent>(PlayerInputComponent);
	InputComp->BindNativeInputAction(InputConfigDataAsset, DBDGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &ADBDSurvivorBase::MoveInput);
	InputComp->BindNativeInputAction(InputConfigDataAsset, DBDGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this, &ADBDSurvivorBase::LookInput);
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
	const FRotator MovementRot(0.f, GetController()->GetControlRotation().Yaw, 0.f);

	if (x != 0.f)
	{
		const FVector RightDir = MovementRot.RotateVector(FVector::RightVector);
		AddMovementInput(RightDir, x);
	}

	if (y != 0.f)
	{
		const FVector ForwardDir = MovementRot.RotateVector(FVector::ForwardVector);
		AddMovementInput(ForwardDir, y);
	}
}

void ADBDSurvivorBase::TryToLook(const float x, const float y)
{
	AddControllerYawInput(x);
	AddControllerPitchInput(y);
}