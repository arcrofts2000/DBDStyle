// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DBDPawnExtensionComponentBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DBDSTYLE_API UDBDPawnExtensionComponentBase : public UActorComponent
{
	GENERATED_BODY()

protected:
	template <class T>
	T* GetOwningPawn() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "Parameter to GetPawn must be derived from APawn!");
		return CastChecked<T>(GetOwner());
	}

	APawn* GetOwningPawn() const { return GetOwningPawn<APawn>(); }

	template <class T>
	T* GetOwningController() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AController>::Value, "Parameter to GetController must be derived from AController!");
		return GetOwningPawn<APawn>()->GetController<T>();
	}
		
};
