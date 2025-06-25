// Attempt at recreating Dead By Daylight for Adam Crofts's Portfolio

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DBDCharacterBase.generated.h"

class UDataAsset_InputConfig;

UCLASS()
class DBDSTYLE_API ADBDCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ADBDCharacterBase();


protected:
	/** Sockets **/
	UPROPERTY(VisibleAnywhere, Category = "Sockets")
	FName HeadSocketName;

	UPROPERTY(VisibleAnywhere, Category = "Sockets")
	FName RightHandSocketName;

	/** Input Actions and IMC **/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UDataAsset_InputConfig> InputConfigDataAsset;


protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;


	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
