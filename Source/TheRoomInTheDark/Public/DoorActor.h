// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorActor.generated.h"

class UHorrorSphereMoveableComponent;

UCLASS()
class THEROOMINTHEDARK_API ADoorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ADoorActor();

	UPROPERTY(Category = "TRID|Moveable", VisibleAnywhere, BlueprintReadOnly)
	UHorrorSphereMoveableComponent* SphereMoveableComponent;
};
