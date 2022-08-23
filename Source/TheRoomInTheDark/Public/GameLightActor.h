// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <GameInteractionInterface.h>
#include "GameLightActor.generated.h"

class UHorrorLightComponent;

UCLASS()
class THEROOMINTHEDARK_API AGameLightActor : public AActor,
	public IGameInteractionInterface
{
	GENERATED_BODY()
	
public:	
	AGameLightActor();

public:
	// IGameInteractionInterface을(를) 통해 상속됨
	virtual bool Interaction_Implementation() override;

	UFUNCTION(Category = "TRID|Light", BlueprintCallable)
	void TrunOnLight();

	UFUNCTION(Category = "TRID|Light", BlueprintCallable)
	void TurnOffLight();

	UFUNCTION(Category = "TRID|Light", BlueprintCallable)
	void ToggleLight();

	UPROPERTY(Category = "TRID|Right", EditAnywhere, BlueprintReadWrite)
	UHorrorLightComponent* HorrorLight;
};
