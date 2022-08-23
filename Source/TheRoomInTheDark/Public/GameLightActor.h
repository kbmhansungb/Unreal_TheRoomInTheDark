// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <GameInteractionInterface.h>
#include "GameLightActor.generated.h"

class AGameLightActor;
class UHorrorLightComponent;

UCLASS(ClassGroup="Prop|Light")
class THEROOMINTHEDARK_API AGameLightActor : public AActor,
	public IGameInteractionInterface
{
	GENERATED_BODY()
	
public:	
	AGameLightActor();

public:
	// IGameInteractionInterface을(를) 통해 상속됨
	virtual bool Interaction_Implementation() override;

	UPROPERTY(Category = "TRID|Right", VisibleAnywhere, BlueprintReadWrite)
	UHorrorLightComponent* HorrorLight;
};
