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
	TObjectPtr<USkeletalMeshComponent> FirstPersonItemMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USkeletalMeshComponent> ThirdPersonItemMesh;

	FORCEINLINE USkeletalMeshComponent* GetThirdPersonItemMesh() const { return ThirdPersonItemMesh; }
	FORCEINLINE USkeletalMeshComponent* GetFirstPersonItemMesh() const { return FirstPersonItemMesh; }


public:
	/** Blueprint Getters **/
	UFUNCTION(BlueprintPure, Category = "Getters", meta = (DisplayName = "Get First Person Item Mesh"))
	FORCEINLINE USkeletalMeshComponent* K2_GetThirdPersonItemMesh() const { return GetThirdPersonItemMesh(); }

	UFUNCTION(BlueprintPure, Category = "Getters", meta = (DisplayName = "Get Third Person Item Mesh"))
	FORCEINLINE USkeletalMeshComponent* K2_GetFirstPersonItemMesh() const { return GetFirstPersonItemMesh(); }
};
