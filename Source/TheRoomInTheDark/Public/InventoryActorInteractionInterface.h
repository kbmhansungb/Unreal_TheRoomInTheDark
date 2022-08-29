// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InventoryActorInteractionInterface.generated.h"

class ACharacter;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInventoryActorInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class THEROOMINTHEDARK_API IInventoryActorInteractionInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(Category = "TRID|Interaction", BlueprintCallable, BlueprintNativeEvent)
	void StartInventoryActorInteraction(ACharacter* Character);
	virtual void StartInventoryActorInteraction_Implementation(ACharacter* Character) = 0;
	
	UFUNCTION(Category = "TRID|Interaction", BlueprintCallable, BlueprintNativeEvent)
	void EndInventoryActorInteraction(ACharacter* Character);
	virtual void EndInventoryActorInteraction_Implementation(ACharacter* Character) = 0;

	UFUNCTION(Category = "TRID|Interaction", BlueprintCallable, BlueprintNativeEvent)
	void CheckInventoryActorInteraction(ACharacter* Character, bool& AllowInteraction);
	virtual void CheckInventoryActorInteraction_Implementation(ACharacter* Character, bool& AllowInteraction) = 0;
};
