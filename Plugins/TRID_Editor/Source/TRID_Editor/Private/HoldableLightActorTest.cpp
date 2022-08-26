// Fill out your copyright notice in the Description page of Project Settings.

#include "HoldableLightActorTest.h"

#include <TheRoomInTheDark/Public/HoldableLightActor.h>
#include <Engine/World.h>

#include "Misc/AutomationTest.h"
#include "Tests/AutomationEditorCommon.h"


void UBindFunctionAndCallTest::BindTurnOnDelegate()
{
	TurnOnDelegateIsCalled = true;
}

void UBindFunctionAndCallTest::BindTurnOffDelegate()
{
	TurnOffDelegateIsCalled = true;
}


IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FTRIDAHoldableLightActorTest,
	"TRID.AHoldableLightActorTest", 
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
);

bool FTRIDAHoldableLightActorTest::RunTest(const FString& parameters)
{
	UWorld* World = FAutomationEditorCommonUtils::CreateNewMap();
	check(World);
	
	AHoldableLightActor* HoldableLightActor = World->SpawnActor<AHoldableLightActor>();
	UBindFunctionAndCallTest* BindFunctionAndCallTest = NewObject<UBindFunctionAndCallTest>();
	check(HoldableLightActor);
	check(BindFunctionAndCallTest);

	{
		FScriptDelegate ScriptDelegate;
		ScriptDelegate.BindUFunction(BindFunctionAndCallTest, FName("BindTurnOnDelegate"));
		HoldableLightActor->TurnOnDelegate.AddUnique(ScriptDelegate);
	}
	{
		FScriptDelegate ScriptDelegate;
		ScriptDelegate.BindUFunction(BindFunctionAndCallTest, FName("BindTurnOffDelegate"));
		HoldableLightActor->TurnOffDelegate.AddUnique(ScriptDelegate);
	}

	HoldableLightActor->LightState = EHoldableLightState::Off;
	HoldableLightActor->SetLightState(EHoldableLightState::On);
	if (!BindFunctionAndCallTest->TurnOnDelegateIsCalled)
	{
		AddError(FString("TurnOnDelegate is not broadcast."));
	}

	HoldableLightActor->LightState = EHoldableLightState::On;
	HoldableLightActor->SetLightState(EHoldableLightState::Off);
	if (!BindFunctionAndCallTest->TurnOffDelegateIsCalled)
	{
		AddError(FString("TurnOffDelegate is not broadcast."));
	}

	return true;
}