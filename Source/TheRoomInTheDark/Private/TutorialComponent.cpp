// Fill out your copyright notice in the Description page of Project Settings.


#include "TutorialComponent.h"

void FActiveTutorialData::SetTutorial(UObject* Outer, TSubclassOf<UTutorialObject> NewClass)
{
	Class = NewClass;
	Instance = NewObject<UTutorialObject>(Outer, NewClass);
}

bool FActiveTutorialData::ChangeDone(UTutorialComponent* TutorialComponent)
{
	if (Instance->IsDone(TutorialComponent))
	{
		State = ETutorialState::Done;
		Instance->EndTutorial(TutorialComponent);

		return true;
	}

	return false;
}

bool FActiveTutorialData::ChangeOngoing(UTutorialComponent* TutorialComponent)
{
	if (Instance->NeedOngoing(TutorialComponent))
	{
		State = ETutorialState::Ongoing;
		Instance->StartTutorial(TutorialComponent);

		return true;
	}

	return false;
}


UTutorialComponent::UTutorialComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTutorialComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UTutorialComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	ProcessTutorial(DeltaTime);
}

void UTutorialComponent::ProcessTutorial(float DeltaTime)
{
	for (int32 Pin = PendingIndicies.Num() - 1; Pin >= 0; --Pin)
	{
		if (StateDatas[PendingIndicies[Pin]].ChangeOngoing(this))
		{
			OngoingIndicies.Add(PendingIndicies[Pin]);
			PendingIndicies.RemoveAt(Pin);
		}
	}

	for (int32 Pin = OngoingIndicies.Num() - 1; Pin >= 0; --Pin)
	{
		if (StateDatas[OngoingIndicies[Pin]].ChangeDone(this))
		{
			OngoingIndicies.RemoveAt(Pin);
		}
		else
		{
			StateDatas[OngoingIndicies[Pin]].Instance->TutorialTick(DeltaTime);
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
		StateDatas.Emplace();
		StateDatas[Index].SetTutorial(this, Tutorials[Index]);
	}
}

void UTutorialComponent::ResetTutorialList()
{
	OngoingIndicies.Reset();
	PendingIndicies.Reset();

	for (int32 Index = 0; Index < StateDatas.Num(); ++Index)
	{
		switch (StateDatas[Index].State)
		{
		case ETutorialState::Ongoing:
			OngoingIndicies.Emplace(Index);
			break;
		case ETutorialState::Pending:
			PendingIndicies.Emplace(Index);
			break;

		case ETutorialState::Done:
		default:
			break;
		}
	}
}

bool UTutorialComponent::IsCorrectinstantiated() const
{
	if (Tutorials.Num() == StateDatas.Num())
	{
		for (int Index = 0; Index < Tutorials.Num(); ++Index)
		{
			if (StateDatas[Index].Class != Tutorials[Index])
			{
				return false;
			}

			if (StateDatas[Index].Instance)
			{
				return false;
			}

			if (StateDatas[Index].Instance->GetClass() != Tutorials[Index])
			{
				return false;
			}
		}

		return true;
	}

	return false;
}

bool UTutorialComponent::CheckTutorialProgress(int DoneNum, int OngoingNum, int PendingNum) const
{
	return
		(StateDatas.Num() - OngoingIndicies.Num() - PendingIndicies.Num()) == DoneNum &&
		OngoingIndicies.Num() == OngoingNum &&
		PendingIndicies.Num() == PendingNum;
}

bool UTutorialComponent::CheckState(int Index, const ETutorialState DesireState) const
{
	return DesireState == StateDatas[Index].State;
}
