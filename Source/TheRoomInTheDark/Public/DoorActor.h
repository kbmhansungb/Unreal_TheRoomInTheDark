// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorActor.generated.h"

class UHorrorSphereMoveableComponent;
class ADoorActor;

UENUM(BlueprintType)
enum class EDoorState : uint8
{
	//NONE,
	LOCK,
	UNLOCK,
};

UCLASS(Abstract, ClassGroup = (Prop, Door))
class THEROOMINTHEDARK_API ADoorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ADoorActor();

	UPROPERTY(Category = "TRID|Door", VisibleAnywhere, BlueprintReadOnly)
	UHorrorSphereMoveableComponent* SphereMoveableComponent;

	UPROPERTY(Category = "TRID|Door", EditAnywhere, BlueprintReadWrite)
	EDoorState DoorStateEnum;
};
