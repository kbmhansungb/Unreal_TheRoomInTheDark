// Fill out your copyright notice in the Description page of Project Settings.


#include "TutorialObject.h"

bool UTutorialObject::NeedActivate_Implementation()
{
	return false;
}

bool UTutorialObject::IsDone_Implementation()
{
	return true;
}

void UTutorialObject::StartTutorial_Implementation(UTutorialComponent* TutorialComponent)
{

}

void UTutorialObject::EndTutorial_Implementation(UTutorialComponent* TutorialComponent)
{

}

void UTutorialObject::TutorialTick_Implementation(float DeltaTime)
{

}
