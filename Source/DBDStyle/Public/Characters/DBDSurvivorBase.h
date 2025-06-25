// Attempt at recreating Dead By Daylight for Adam Crofts's Portfolio

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DBDSurvivorBase.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class UDataAsset_InputConfig;
struct FInputActionValue;

UCLASS()
class DBDSTYLE_API ADBDSurvivorBase : public ACharacter
{
	GENERATED_BODY()

public:
	ADBDSurvivorBase();


protected:
	/** Sockets **/
	UPROPERTY(VisibleAnywhere, Category = "Sockets")
	FName RightHandSocketName;


	/** Components **/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USpringArmComponent> SpringArmComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UCameraComponent> ThirdPersonCamera;


	/** New Input **/
	//@TODO: Remove old Input Actions!
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UDataAsset_InputConfig> InputConfigDataAsset;


	/** Input Functions **/
	void MoveInput(const FInputActionValue& InputValue);
	void LookInput(const FInputActionValue& InputValue);
	void BeginCrouchInput();
	void EndCrouchInput();



public:
	/** Blueprint Getters **/
	UFUNCTION(BlueprintPure, Category = "Survivor|Getter", meta = (DisplayName = "Get Third Person Camera"))
	FORCEINLINE UCameraComponent* GetThirdPersonCamera() { return ThirdPersonCamera; }

	/** BlueprintCallable Input Functions **/
	UFUNCTION(BlueprintCallable, Category = "Survivor|Input", meta = (DisplayName = "Try To Move"))
	void TryToMove(const float x, const float y);

	UFUNCTION(BlueprintCallable, Category = "Survivor|Input", meta = (DisplayName = "Try To Look"))
	void TryToLook(const float x, const float y);


protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
