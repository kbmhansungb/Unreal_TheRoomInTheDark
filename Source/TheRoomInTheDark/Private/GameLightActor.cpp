
#include "GameLightActor.h"
#include <HorrorEvent/Public/HorrorEventInstance_Light.h>

AGameLightActor::AGameLightActor()
{
	//PrimaryActorTick.bCanEverTick = true;

	HorrorLight = CreateDefaultSubobject<UHorrorLightComponent>(FName("HorrorLight"));
}

bool AGameLightActor::Interaction_Implementation()
{
	ToggleLight();

	return true;
}

void AGameLightActor::TrunOnLight()
{
	HorrorLight->SetLgiht(true);
	HorrorLight->UpdateLight();
}

void AGameLightActor::TurnOffLight()
{
	HorrorLight->SetLgiht(false);
	HorrorLight->UpdateLight();
}

void AGameLightActor::ToggleLight()
{
	HorrorLight->ToggleLight();
}
