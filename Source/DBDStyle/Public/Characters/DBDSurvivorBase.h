// Attempt at recreating Dead By Daylight for Adam Crofts's Portfolio

#pragma once

#include "CoreMinimal.h"
#include "Characters/DBDCharacterBase.h"
#include "DBDSurvivorBase.generated.h"

class USpringArmComponent;
class UCameraComponent;
class USurvivorItemComponent;
class UInputMappingContext;
class UInputAction;
class UDataAsset_InputConfig;
struct FInputActionValue;

UCLASS()
class DBDSTYLE_API ADBDSurvivorBase : public ADBDCharacterBase
{
	GENERATED_BODY()

public:
	ADBDSurvivorBase();


protected:
	/** Components **/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USpringArmComponent> SpringArmComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UCameraComponent> ThirdPersonCamera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USurvivorItemComponent> SurvivorItemComp;


	/** Input Functions **/
	void MoveInput(const FInputActionValue& InputValue);
	void LookInput(const FInputActionValue& InputValue);
	void BeginCrouchInput();
	void EndCrouchInput();



public:
	FORCEINLINE UCameraComponent* GetThirdPersonCamera() const { return ThirdPersonCamera; }
	FORCEINLINE USurvivorItemComponent* GetSurvivorItemComponent() const { return SurvivorItemComp; }



public:
	/** Blueprint Getters **/
	UFUNCTION(BlueprintPure, Category = "Survivor|Getter", meta = (DisplayName = "Get Third Person Camera"))
	FORCEINLINE UCameraComponent* K2_GetThirdPersonCamera() const { return GetThirdPersonCamera(); }

	UFUNCTION(BlueprintPure, Category = "Survivor|Getter", meta = (DisplayName = "Get Survivor Item Component"))
	FORCEINLINE USurvivorItemComponent* K2_GetSurvivorItemComponent() const { return GetSurvivorItemComponent(); }



	/** BlueprintCallable Input Functions **/
	UFUNCTION(BlueprintCallable, Category = "Survivor|Input", meta = (DisplayName = "Try To Move"))
	void TryToMove(const float x, const float y);

	UFUNCTION(BlueprintCallable, Category = "Survivor|Input", meta = (DisplayName = "Try To Look"))
	void TryToLook(const float x, const float y);


protected:
	//~ Begin APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
