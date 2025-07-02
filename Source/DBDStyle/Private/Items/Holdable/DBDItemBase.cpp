// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Holdable/DBDItemBase.h"


ADBDItemBase::ADBDItemBase()
{
	PrimaryActorTick.bCanEverTick = false;

	ItemStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Item Static Mesh");
	ItemStaticMesh->SetupAttachment(GetRootComponent());
	ItemStaticMesh->SetCollisionProfileName("No Collision");

	ItemSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Item Skeletal Mesh");
	ItemSkeletalMesh->SetupAttachment(GetRootComponent());
	ItemSkeletalMesh->SetCollisionProfileName("No Collision");

}