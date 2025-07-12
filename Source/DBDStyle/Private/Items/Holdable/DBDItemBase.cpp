// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Holdable/DBDItemBase.h"


ADBDItemBase::ADBDItemBase()
{
	PrimaryActorTick.bCanEverTick = false;

	FirstPersonItemMesh = CreateDefaultSubobject<USkeletalMeshComponent>("First Person Item Mesh");
	SetRootComponent(FirstPersonItemMesh);
	FirstPersonItemMesh->SetCollisionProfileName("No Collision");

	ThirdPersonItemMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Third Person Item Mesh");
	ThirdPersonItemMesh->SetupAttachment(GetRootComponent());
	ThirdPersonItemMesh->SetCollisionProfileName("No Collision");

}