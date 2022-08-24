// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameInteractionInterface.generated.h"

class ACharacter;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGameInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class THEROOMINTHEDARK_API IGameInteractionInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(Category = "TRID|Interaction", BlueprintCallable, BlueprintNativeEvent)
	bool StartInteraction(ACharacter* Character);
	virtual bool StartInteraction_Implementation(ACharacter* Character) = 0;
	
	UFUNCTION(Category = "TRID|Interaction", BlueprintCallable, BlueprintNativeEvent)
	void EndInteraction(ACharacter* Character);
	virtual void EndInteraction_Implementation(ACharacter* Character) = 0;
};
