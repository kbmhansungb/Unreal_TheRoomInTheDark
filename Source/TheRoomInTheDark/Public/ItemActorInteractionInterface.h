// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ItemActorInteractionInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UItemActorInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class THEROOMINTHEDARK_API IItemActorInteractionInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(Category = "TRID|Interaction", BlueprintCallable, BlueprintNativeEvent)
	void StartItemActorInteraction(ACharacter* Character);
	virtual void StartItemActorInteraction_Implementation(ACharacter* Character) = 0;
	
	UFUNCTION(Category = "TRID|Interaction", BlueprintCallable, BlueprintNativeEvent)
	void EndItemActorInteraction(ACharacter* Character);
	virtual void EndItemActorInteraction_Implementation(ACharacter* Character) = 0;
};
