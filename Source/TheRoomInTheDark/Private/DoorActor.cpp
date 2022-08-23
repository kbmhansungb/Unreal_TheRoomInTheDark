
#include "DoorActor.h"
#include <HorrorCore/Public/HorrorSphereMoveableComponent.h>

// Sets default values
ADoorActor::ADoorActor()
{
	//PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(FName("Root"));

	SphereMoveableComponent = CreateDefaultSubobject<UHorrorSphereMoveableComponent>(FName("Moveable"));
	SphereMoveableComponent->MaintainY = false;
	SphereMoveableComponent->AttachTo(RootComponent);
}
