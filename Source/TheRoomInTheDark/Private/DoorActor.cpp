
#include "DoorActor.h"
#include <HorrorCore/Public/HorrorSphereMoveableComponent.h>

// Sets default values
ADoorActor::ADoorActor()
{
	//PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(FName("Root"));
	RootComponent->Mobility = EComponentMobility::Movable;

	SphereMoveableComponent = CreateDefaultSubobject<UHorrorSphereMoveableComponent>(FName("Moveable"));
	SphereMoveableComponent->MaintainX = false;
	SphereMoveableComponent->AttachTo(RootComponent);
}

void ADoorActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	SetDoorState(DoorStateEnum);
}

void ADoorActor::MatchDoorState()
{
	SetDoorState(DoorStateEnum);
}

void ADoorActor::UpdateDoorState(EDoorState NewStateEnum)
{
	if (DoorStateEnum == NewStateEnum)
	{
		return;
	}

	DoorStateEnum = NewStateEnum;
	SetDoorState(DoorStateEnum);
}

void ADoorActor::SetDoorState(EDoorState NewStateEnum)
{
	switch (NewStateEnum)
	{
	case EDoorState::LOCK:
	{
		SphereMoveableComponent->MaintainX = false;
		SphereMoveableComponent->MaintainY = false;
		SphereMoveableComponent->MaintainZ = false;

		if (LockDoorDelegate.IsBound())
		{
			LockDoorDelegate.Broadcast(this);
		}
	}
	break;
	case EDoorState::UNLOCK:
	{
		SphereMoveableComponent->MaintainX = true;
		SphereMoveableComponent->MaintainY = true;
		SphereMoveableComponent->MaintainZ = false;

		if (UnLockDoorDelegate.IsBound())
		{
			UnLockDoorDelegate.Broadcast(this);
		}
	}
	break;

	default:
		check(false);
		break;
	}
}
