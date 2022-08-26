// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <GameInteractionInterface.h>
#include "GameLightActor.generated.h"

class AGameLightActor;
class UHorrorLightComponent;

UCLASS(Abstract, ClassGroup = (Prop, Light))
class THEROOMINTHEDARK_API AGameLightActor : public AActor,
	public IGameInteractionInterface
{
	GENERATED_BODY()
	
public:	
	AGameLightActor();

	// IGameInteractionInterface을(를) 통해 상속됨
public:
	virtual bool StartInteraction_Implementation(ACharacter* Character) override;
	virtual void EndInteraction_Implementation(ACharacter* Character) override;

	UPROPERTY(Category = "TRID|Light", VisibleAnywhere, BlueprintReadWrite)
	UHorrorLightComponent* HorrorLight;
};
