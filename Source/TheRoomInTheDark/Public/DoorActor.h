// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorActor.generated.h"

class UHorrorSphereMoveableComponent;
class ADoorActor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDoorDelegate, ADoorActor*, DoorActor);

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
	virtual void BeginPlay() override;

	UPROPERTY(Category = "TRID|Door", EditAnywhere, BlueprintReadWrite)
	EDoorState DoorStateEnum;
	
	UFUNCTION(Category = "TRID|Door", CallInEditor, BlueprintCallable)
	void MatchDoorState();

public:
	UPROPERTY(Category = "TRID|Door", VisibleAnywhere, BlueprintReadOnly)
	UHorrorSphereMoveableComponent* SphereMoveableComponent;

public:
	UPROPERTY(BlueprintAssignable)
	FDoorDelegate LockDoorDelegate;
	
	UPROPERTY(BlueprintAssignable)
	FDoorDelegate UnLockDoorDelegate;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BindSphereMoveableBlockingDelegateWhenUnLock(UHorrorSphereMoveableComponent* PublisherSphereMoveableComponent);
	
	UFUNCTION(BlueprintImplementableEvent)
	void BindSphereMoveableMoveDelegateWhenUnLock(UHorrorSphereMoveableComponent* PublisherSphereMoveableComponent);
	
	UFUNCTION(BlueprintImplementableEvent)
	void BindSphereMoveablePrepareMovingDelegateWhenLock(UHorrorSphereMoveableComponent* PublisherSphereMoveableComponent);

#pragma region Implementation

public:
	void UpdateDoorState(EDoorState NewStateEnum);

private:
	void SetDoorState(EDoorState NewStateEnum);

#pragma endregion

};
