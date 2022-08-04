// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TutorialComponent.h"
#include "TutorialTest.generated.h"

UCLASS( ClassGroup=(Tutorial) )
class UTestTutorialObject : public UTutorialObject
{
	GENERATED_BODY()

	// UTutorialObject에서 상속됨
public:
	virtual bool NeedOngoing_Implementation(UTutorialComponent* TutorialComponent) override;
	virtual bool IsDone_Implementation(UTutorialComponent* TutorialComponent) override;

	virtual void StartTutorial_Implementation(UTutorialComponent* TutorialComponent) override;
	virtual void EndTutorial_Implementation(UTutorialComponent* TutorialComponent) override;
	virtual void TutorialTick_Implementation(float DeltaTime) override;
};