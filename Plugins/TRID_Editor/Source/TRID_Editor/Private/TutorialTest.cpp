// Fill out your copyright notice in the Description page of Project Settings.


#include "TutorialTest.h"
#include "TutorialComponent.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTutorialTest, "Tutorial.ComponentTest", 
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)

bool FTutorialTest::RunTest(const FString& parameters)
{
	return true;
}