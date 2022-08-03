//// Copyright Epic Games, Inc. All Rights Reserved.
//
//#include "TRID_EditorEdMode.h"
//#include "TRID_EditorEdModeToolkit.h"
//#include "Toolkits/ToolkitManager.h"
//#include "EditorModeManager.h"
//
//const FEditorModeID FTRID_EditorEdMode::EM_TRID_EditorEdModeId = TEXT("EM_TRID_EditorEdMode");
//
//FTRID_EditorEdMode::FTRID_EditorEdMode()
//{
//
//}
//
//FTRID_EditorEdMode::~FTRID_EditorEdMode()
//{
//
//}
//
//void FTRID_EditorEdMode::Enter()
//{
//	FEdMode::Enter();
//
//	if (!Toolkit.IsValid() && UsesToolkits())
//	{
//		Toolkit = MakeShareable(new FTRID_EditorEdModeToolkit);
//		Toolkit->Init(Owner->GetToolkitHost());
//	}
//}
//
//void FTRID_EditorEdMode::Exit()
//{
//	if (Toolkit.IsValid())
//	{
//		FToolkitManager::Get().CloseToolkit(Toolkit.ToSharedRef());
//		Toolkit.Reset();
//	}
//
//	// Call base Exit method to ensure proper cleanup
//	FEdMode::Exit();
//}
//
//bool FTRID_EditorEdMode::UsesToolkits() const
//{
//	return true;
//}
//
//
//
//
