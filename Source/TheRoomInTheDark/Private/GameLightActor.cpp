
#include "GameLightActor.h"
#include <HorrorEvent/Public/HorrorEventInstance_Light.h>

AGameLightActor::AGameLightActor()
{
	//PrimaryActorTick.bCanEverTick = true;

	HorrorLight = CreateDefaultSubobject<UHorrorLightComponent>(FName("HorrorLight"));
}

void AGameLightActor::TrunOnLight()
{
}

void AGameLightActor::TurnOffLight()
{

}

