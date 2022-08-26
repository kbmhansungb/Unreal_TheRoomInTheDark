// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <HorrorSystem/Public/HorrorHoldableActor.h>
#include <HorrorSystem/Public/HorrorItemActorInterface.h>
#include "HoldableLightActor.generated.h"

class AHoldableLightActor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHoldableLightDelegate, AHoldableLightActor*, PublisherHoldableLight);

UENUM(BlueprintType)
enum class HoldableLightState : uint8
{
	//NONE,
	Off,
	On,
};

UCLASS()
class THEROOMINTHEDARK_API AHoldableLightActor : public AHorrorHoldableActor,
	public IHorrorItemActorInterface
{
	GENERATED_BODY()
	
public:	
	AHoldableLightActor() = default;

public:
	UFUNCTION(Category = "TRID|Light", BlueprintCallable)
	void SetLightState(HoldableLightState NewLightState);

	UPROPERTY(Category = "TRID|Light", EditAnywhere, BlueprintReadWrite, BlueprintSetter=SetLightState)
	HoldableLightState LightState;

protected:
	UFUNCTION(Category = "TRID|Light", BlueprintCallable, BlueprintImplementableEvent)
	void TurnOnLight();
	
	UFUNCTION(Category = "TRID|Light", BlueprintCallable, BlueprintImplementableEvent)
	void TurnOffLight();

	// IHorrorItemActorInterface에서 상속됨
public:
	virtual void GetItemInterface_Implementation(TScriptInterface<IHorrorItemInterface>& ItemInterface);
	virtual void HoldItemActor_Implementation(UHorrorHandComponent* HandComponent);
	virtual void ReleaseItemActor_Implementation(UHorrorHandComponent* HandComponent);

public:
	UPROPERTY(Category = "TRID|Light", BlueprintAssignable, VisibleAnywhere, BlueprintCallable)
	FHoldableLightDelegate TurnOnDelegate;

	UPROPERTY(Category = "TRID|Light", BlueprintAssignable, VisibleAnywhere, BlueprintCallable)
	FHoldableLightDelegate TurnOffDelegate;
};
