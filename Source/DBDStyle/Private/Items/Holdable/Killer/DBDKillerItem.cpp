// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Holdable/Killer/DBDKillerItem.h"
#include "Components/BoxComponent.h"

ADBDKillerItem::ADBDKillerItem()
{
	ItemCollision = CreateDefaultSubobject<UBoxComponent>("Item Collision");
	ItemCollision->SetupAttachment(GetRootComponent());
	ItemCollision->SetBoxExtent(FVector(20.f));
	ItemCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}