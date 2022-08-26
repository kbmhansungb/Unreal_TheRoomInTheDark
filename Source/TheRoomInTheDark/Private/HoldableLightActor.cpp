// Fill out your copyright notice in the Description page of Project Settings.


#include "HoldableLightActor.h"


void AHoldableLightActor::SetLightState(EHoldableLightState NewLightState)
{
	if (LightState == NewLightState)
	{
		return;
	}

	LightState = NewLightState;
	UpdateLightState();
}

void AHoldableLightActor::UpdateLightState()
{
	switch (LightState)
	{
	case EHoldableLightState::Off:
	{
		TurnOffLight();

		if (TurnOffDelegate.IsBound())
		{
			TurnOffDelegate.Broadcast(this);
		}
	}
	break;
	case EHoldableLightState::On:
	{
		TurnOnLight();

		if (TurnOnDelegate.IsBound())
		{
			TurnOnDelegate.Broadcast(this);
		}
	}
	break;

	default:
		check(false);
		break;
	}
}

void AHoldableLightActor::GetItemInterface_Implementation(TScriptInterface<IHorrorItemInterface>& ItemInterface)
{
	ItemInterface = TScriptInterface<IHorrorItemInterface>();
}

void AHoldableLightActor::HoldItemActor_Implementation(UHorrorHandComponent* HandComponent)
{

}

void AHoldableLightActor::ReleaseItemActor_Implementation(UHorrorHandComponent* HandComponent)
{

}

