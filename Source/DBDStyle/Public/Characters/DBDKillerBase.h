// Attempt at recreating Dead By Daylight for Adam Crofts's Portfolio

#pragma once

#include "CoreMinimal.h"
#include "Characters/DBDCharacterBase.h"
#include "DBDKillerBase.generated.h"

class UCameraComponent;
class USpotLightComponent;
class UInputMappingContext;
class UInputAction;
class UDataAsset_InputConfig;
class UKillerCombatComponent;
struct FInputActionValue;

UCLASS()
class DBDSTYLE_API ADBDKillerBase : public ADBDCharacterBase
{
	GENERATED_BODY()

public:
	ADBDKillerBase();

protected:
	
	/** Components **/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USkeletalMeshComponent> FirstPersonMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UCameraComponent> FirstPersonCamera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USpotLightComponent> KillerAuraLight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UKillerCombatComponent> KillerCombatComp;


	/** Input Functions **/
	void MoveInput(const FInputActionValue& InputValue);
	void LookInput(const FInputActionValue& InputValue);
	void PrimaryAttackInput();
	void SecondaryAttackInput();



public:
	FORCEINLINE USkeletalMeshComponent* GetFirstPersonMesh() const { return FirstPersonMesh; }
	FORCEINLINE UCameraComponent* GetFirstPersonCamera() const { return FirstPersonCamera; }
	FORCEINLINE UKillerCombatComponent* GetKillerCombatComponent() const { return KillerCombatComp; }
		

public:
	/** Blueprint Getters **/
	UFUNCTION(BlueprintPure, Category = "Killer|Getter", meta = (DisplayName = "Get First Person Mesh"))
	FORCEINLINE USkeletalMeshComponent* K2_GetFirstPersonMesh() const { return GetFirstPersonMesh(); }
	
	UFUNCTION(BlueprintPure, Category = "Killer|Getter", meta = (DisplayName = "Get First Person Camera"))
	FORCEINLINE UCameraComponent* K2_GetFirstPersonCamera() const { return GetFirstPersonCamera(); }

	UFUNCTION(BlueprintPure, Category = "Killer|Getter", meta = (DisplayName = "Get Killer Combat Component"))
	FORCEINLINE UKillerCombatComponent* K2_GetKillerCombatComponent() const { return GetKillerCombatComponent(); }


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
	//~ Begin APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
