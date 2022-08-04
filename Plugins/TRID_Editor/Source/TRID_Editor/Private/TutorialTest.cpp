// Fill out your copyright notice in the Description page of Project Settings.


#include "TutorialTest.h"
#include "Misc/AutomationTest.h"

bool OngoingSwitch;
bool DoneSwith;

bool IsStart;
bool IsEnd;

bool UTestTutorialObject::NeedOngoing_Implementation(UTutorialComponent* TutorialComponent)
{
	return OngoingSwitch;
}

bool UTestTutorialObject::IsDone_Implementation(UTutorialComponent* TutorialComponent)
{
	return DoneSwith;
}

void UTestTutorialObject::StartTutorial_Implementation(UTutorialComponent* TutorialComponent)
{
	IsStart = true;
}

void UTestTutorialObject::EndTutorial_Implementation(UTutorialComponent* TutorialComponent)
{
}

void UTestTutorialObject::TutorialTick_Implementation(float DeltaTime)
{
	IsEnd = true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTutorialComponentTest, "Tutorial.ComponentTest", 
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)

bool FTutorialComponentTest::RunTest(const FString& parameters)
{
	OngoingSwitch = false;
	DoneSwith = false;

	IsStart = false;
	IsEnd = false;

	UTutorialComponent* Component = NewObject<UTutorialComponent>();

	if (!Component)
	{
		return false;
	}

	// 생성 테스트
	// 생성되는지를 확인하기 위한 테스트
	UClass* TestClass = UTestTutorialObject::StaticClass();
	Component->Tutorials.Add(TestClass);
	Component->ResetTutorialComponent();

	// 준비
	const auto& StateDatas = Component->GetStateDatas();

	auto EqualInstancedNum = [&]() -> bool {
		return Component->Tutorials.Num() == StateDatas.Num();
	};
	auto CheckDesireTutorialState = [&](int DoneNum, int OngoingNum, int PendingNum) -> bool {
		return
			(StateDatas.Num() - Component->OngoingIndicies.Num() - Component->PendingIndicies.Num()) == DoneNum &&
			Component->OngoingIndicies.Num() == OngoingNum &&
			Component->PendingIndicies.Num() == PendingNum;
	};
	auto CheckState = [&](int Index, const ETutorialState DesireState) -> bool {
		return
			DesireState == StateDatas[Index].State &&
			DesireState == ETutorialState::Pending ? IsStart == false && IsEnd == false : true &&
			DesireState == ETutorialState::Pending ? IsStart == true && IsEnd == false : true &&
			DesireState == ETutorialState::Pending ? IsStart == true && IsEnd == true : true;
	};
	
	if (!EqualInstancedNum())
	{
		AddError(FString("Instanced is not equal."));
	}

	// UTestTutorialObject를 생성했는지 확인하는 테스트
	if (!CheckDesireTutorialState(0, 0, 1))
	{
		AddError(FString("In the initial state after reset, State should be Pending state."));
	}

	if (!CheckState(0, ETutorialState::Pending))
	{
		AddError(FString("Desired state and result do not match."));
	}

	//
	Component->ProcessTutorial(0.f);
	if (!CheckDesireTutorialState(0, 0, 1))
	{
		AddError(FString("Status changed unintentionally"));
	}

	//
	OngoingSwitch = true;
	Component->ProcessTutorial(0.f);
	if (!CheckDesireTutorialState(0, 1, 0))
	{
		AddError(FString("No transition from pending to in ongoing."));
	}

	if (!CheckState(0, ETutorialState::Ongoing))
	{
		AddError(FString("Desired state and result do not match."));
	}

	// 
	Component->ProcessTutorial(0.f);
	if (!CheckDesireTutorialState(0, 1, 0))
	{
		AddError(FString("Status changed unintentionally"));
	}

	//
	DoneSwith = true;
	Component->ProcessTutorial(0.f);
	if (!CheckDesireTutorialState(1, 0, 0))
	{
		AddError(FString("No transition from pending to in ongoing."));
	}

	if (!CheckState(0, ETutorialState::Done))
	{
		AddError(FString("Desired state and result do not match."));
	}

	// 
	Component->ProcessTutorial(0.f);
	if (!CheckDesireTutorialState(1, 0, 0))
	{
		AddError(FString("Status changed unintentionally"));
	}

	return true;
}