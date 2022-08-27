// Copyright Epic Games, Inc. All Rights Reserved.

#include "TRID_Editor.h"

#define LOCTEXT_NAMESPACE "FTRID_EditorModule"

void FTRID_EditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	// FEditorModeRegistry::Get().RegisterMode<FTRID_EditorEdMode>(FTRID_EditorEdMode::EM_TRID_EditorEdModeId, LOCTEXT("TRID_EditorEdModeName", "TRID_EditorEdMode"), FSlateIcon(), true);
}

void FTRID_EditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	// FEditorModeRegistry::Get().UnregisterMode(FTRID_EditorEdMode::EM_TRID_EditorEdModeId);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTRID_EditorModule, TRID_Editor)