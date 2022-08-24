
#include "GameLightActor.h"
#include <HorrorEvent/Public/HorrorEventInstance_Light.h>

AGameLightActor::AGameLightActor()
{
	//PrimaryActorTick.bCanEverTick = true;

	HorrorLight = CreateDefaultSubobject<UHorrorLightComponent>(FName("HorrorLight"));
}

bool AGameLightActor::StartInteraction_Implementation(ACharacter* Character)
{
	HorrorLight->ToggleLight();

	return true;
}

void AGameLightActor::EndInteraction_Implementation(ACharacter* Character)
{

}
