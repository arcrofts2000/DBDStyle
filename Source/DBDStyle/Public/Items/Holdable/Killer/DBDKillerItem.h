// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Holdable/DBDItemBase.h"
#include "DBDKillerItem.generated.h"

class UBoxComponent;

/**
 * 
 */
UCLASS()
class DBDSTYLE_API ADBDKillerItem : public ADBDItemBase
{
	GENERATED_BODY()

public:
	ADBDKillerItem();


protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UBoxComponent> ItemCollision;


public:
	/** Blueprint Getters **/
	UFUNCTION(BlueprintPure, Category = "Getters", meta = (DisplayName = "Get Item Collision"))
	FORCEINLINE UBoxComponent* GetItemCollision() const { return ItemCollision; }
	
};
