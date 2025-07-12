// Attempt at recreating Dead By Daylight for Adam Crofts's Portfolio

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "DBDCharacterBase.generated.h"

class UDataAsset_InputConfig;
class UDataAsset_StartupDataBase;
class UDBDAbilitySystemComponent;
class UDBDAttributeSet;

UCLASS()
class DBDSTYLE_API ADBDCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ADBDCharacterBase();

	//~ Begin AbilitySystemInterface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
	//~ End AbilitySystemInterface

protected:
	/** Sockets **/
	UPROPERTY(VisibleAnywhere, Category = "Sockets")
	FName HeadSocketName;

	UPROPERTY(VisibleAnywhere, Category = "Sockets")
	FName RightHandSocketName;

	/** Input Actions and IMC **/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UDataAsset_InputConfig> InputConfigDataAsset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Data")
	TSoftObjectPtr<UDataAsset_StartupDataBase> StartupData;


	/** AbilitySystem **/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AbilitySystem")
	TObjectPtr<UDBDAbilitySystemComponent> AbilitySystemComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AbilitySystem")
	TObjectPtr<UDBDAttributeSet> Attributes;



public:
	FORCEINLINE UDBDAbilitySystemComponent* GetAbilitySystemComp() const { return AbilitySystemComp; }
	FORCEINLINE UDBDAttributeSet* GetAttributes() const { return Attributes; }




public:
	/** Ability System Getters **/
	UFUNCTION(BlueprintPure, Category = "Getters", meta = (DisplayName = "Get DBD Ability System Component"))
	FORCEINLINE UDBDAbilitySystemComponent* K2_GetAbilitySystemComp() const { return GetAbilitySystemComp(); }

	UFUNCTION(BlueprintPure, Category = "Getters", meta = (DisplayName = "Get Attributes"))
	FORCEINLINE UDBDAttributeSet* K2_GetAttributes() const { return GetAttributes(); }



protected:
	//~ Begin APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;


	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
