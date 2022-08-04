// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TutorialObject.generated.h"

class UTutorialComponent;

/**
 * UTutorialObject is the object that controls the tutorial with a start and an end.
 */
UCLASS( ClassGroup=(Tutorial) )
class THEROOMINTHEDARK_API UTutorialObject : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool NeedOngoing(UTutorialComponent* TutorialComponent);
	virtual bool NeedOngoing_Implementation(UTutorialComponent* TutorialComponent);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool IsDone(UTutorialComponent* TutorialComponent);
	virtual bool IsDone_Implementation(UTutorialComponent* TutorialComponent);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void StartTutorial(UTutorialComponent* TutorialComponent);
	virtual void StartTutorial_Implementation(UTutorialComponent* TutorialComponent);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void EndTutorial(UTutorialComponent* TutorialComponent);
	virtual void EndTutorial_Implementation(UTutorialComponent* TutorialComponent);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void TutorialTick(float DeltaTime);
	virtual void TutorialTick_Implementation(float DeltaTime);
};
