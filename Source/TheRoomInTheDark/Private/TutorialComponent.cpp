// Fill out your copyright notice in the Description page of Project Settings.


#include "TutorialComponent.h"

UTutorialComponent::UTutorialComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	ResetTutorialComponent();
}

UTutorialComponent::~UTutorialComponent()
{
}

void UTutorialComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UTutorialComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	for (int32 Pin = QueueIndex.Num() - 1; Pin >= 0; --Pin)
	{
		if (StateDatas[QueueIndex[Pin]].ChangeOngoing(this))
		{
			ActiveIndex.Emplace(QueueIndex[Pin]);
			QueueIndex.RemoveAt(Pin);
		}
	}

	for (int32 Pin = ActiveIndex.Num() - 1; Pin >= 0; --Pin)
	{
		if (StateDatas[QueueIndex[Pin]].ChangeDone(this))
		{
			ActiveIndex.RemoveAt(Pin);
		}
		else
		{
			StateDatas[QueueIndex[Pin]].Instance->TutorialTick(DeltaTime);
		}
	}
}

void UTutorialComponent::ResetTutorialComponent()
{
	ResetTutorialData();
	ResetTutorialList();
}

void UTutorialComponent::ResetTutorialData()
{
	StateDatas.Reset();
	StateDatas.Reserve(Tutorials.Num());

	for (int Index = 0; Index < Tutorials.Num(); ++Index)
	{
		StateDatas[Index].SetTutorial(Tutorials[Index]);
	}
}

void UTutorialComponent::ResetTutorialList()
{
	ActiveIndex.Reset();
	QueueIndex.Reset();

	for (int32 Index = 0; Index < StateDatas.Num(); ++Index)
	{
		switch (StateDatas[Index].State)
		{
		case ETutorialState::Ongoing:
			ActiveIndex.Emplace(Index);
			break;
		case ETutorialState::Pending:
			QueueIndex.Emplace(Index);
			break;

		case ETutorialState::Done:
		default:
			break;
		}
	}
}
