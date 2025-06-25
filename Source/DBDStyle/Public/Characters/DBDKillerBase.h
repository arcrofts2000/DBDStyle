// Attempt at recreating Dead By Daylight for Adam Crofts's Portfolio

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DBDKillerBase.generated.h"

class UCameraComponent;
class USpotLightComponent;
class UInputMappingContext;
class UInputAction;
class UDataAsset_InputConfig;
struct FInputActionValue;

UCLASS()
class DBDSTYLE_API ADBDKillerBase : public ACharacter
{
	GENERATED_BODY()

public:
	ADBDKillerBase();

protected:
	/** Sockets **/
	UPROPERTY(VisibleAnywhere, Category = "Sockets")
	FName HeadSocketName;

	UPROPERTY(VisibleAnywhere, Category = "Sockets")
	FName RightHandSocketName;


	/** Components **/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USkeletalMeshComponent> FirstPersonMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UCameraComponent> FirstPersonCamera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USpotLightComponent> KillerAuraLight;


	/** Input Actions and IMC **/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UDataAsset_InputConfig> InputConfigDataAsset;


	/** Input Functions **/
	void MoveInput(const FInputActionValue& InputValue);
	void LookInput(const FInputActionValue& InputValue);
	void PrimaryAttackInput();
	void SecondaryAttackInput();
		

public:
	/** Blueprint Getters **/
	UFUNCTION(BlueprintPure, Category = "Killer|Getter", meta = (DisplayName = "Get First Person Mesh"))
	FORCEINLINE USkeletalMeshComponent* GetFirstPersonMesh() { return FirstPersonMesh; }
	
	UFUNCTION(BlueprintPure, Category = "Killer|Getter", meta = (DisplayName = "Get First Person Camera"))
	FORCEINLINE UCameraComponent* GetFirstPersonCamera() { return FirstPersonCamera; }


	/** BlueprintCallable Input Functions **/
	UFUNCTION(BlueprintCallable, Category = "Killer|Input", meta = (DisplayName = "Try to Move"))
	void TryToMove(const float x, const float y);

	UFUNCTION(BlueprintCallable, Category = "Killer|Input", meta = (DisplayName = "Try to Look"))
	void TryToLook(const float x, const float y);

	/* These are Implementable incase designers want to use Blueprints to create or test attacks */
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Killer|Input", meta = (DisplayName = "Primary Attack"))
	void TryPrimaryAttack();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Killer|Input", meta = (DisplayName = "Secondary Attack"))
	void TrySecondaryAttack();


protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
