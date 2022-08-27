// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <UObject/Object.h>
#include "HoldableLightActorTest.generated.h"

UCLASS()
class UBindFunctionAndCallTest : public UObject
{
	GENERATED_BODY()

public:
	bool TurnOnDelegateIsCalled = false;
	UFUNCTION()
	void BindTurnOnDelegate();

	bool TurnOffDelegateIsCalled = false;
	UFUNCTION()
	void BindTurnOffDelegate();
};