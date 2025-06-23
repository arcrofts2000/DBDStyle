// Attempt at recreating Dead By Daylight for Adam Crofts's Portfolio

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DBDKillerBase.generated.h"

UCLASS()
class DBDSTYLE_API ADBDKillerBase : public ACharacter
{
	GENERATED_BODY()

public:
	ADBDKillerBase();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
