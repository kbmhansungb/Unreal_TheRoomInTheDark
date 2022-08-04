// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MediaTexture.h"
#include "TutorialWidget.generated.h"

class UTexture2D;
class UFileMediaSource;
/**
 * 
 */
UCLASS(Abstract)
class THEROOMINTHEDARK_API UTutorialWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void AddComment(const FString& Comment);
	
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void AddTexture(UTexture2D* Texture);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void AddMedia(UFileMediaSource* FileMediaSource);

public:
	UFUNCTION(BlueprintCallable)
	void UpdateMediaTexture(UMediaTexture* mediaTexture);
};
