// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DBDItemBase.generated.h"

UCLASS()
class DBDSTYLE_API ADBDItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ADBDItemBase();


protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> ItemStaticMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USkeletalMeshComponent> ItemSkeletalMesh;


public:
	/** Blueprint Getters **/
	UFUNCTION(BlueprintPure, Category = "Getters", meta = (DisplayName = "Get Item (StaticMesh)"))
	FORCEINLINE UStaticMeshComponent* GetItemStaticMesh() const { return ItemStaticMesh; }

	UFUNCTION(BlueprintPure, Category = "Getters", meta = (DisplayName = "Get Item (SkeletalMesh)"))
	FORCEINLINE USkeletalMeshComponent* GetItemSkeletalMesh() const { return ItemSkeletalMesh; }
};
