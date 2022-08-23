// Fill out your copyright notice in the Description page of Project Settings.


#include "TutorialWidget.h"

void UTutorialWidget::UpdateMediaTexture(UMediaTexture* mediaTexture)
{
	check(mediaTexture);

	mediaTexture->UpdateResource();
}
