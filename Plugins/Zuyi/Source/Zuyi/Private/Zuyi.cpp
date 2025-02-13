// Copyright Epic Games, Inc. All Rights Reserved.

#include "Zuyi.h"
#include "Engine/Blueprint.h"
#include "LevelEditorOutlinerSettings.h"
#include "IPlacementModeModule.h"
#include "ActorFactories/ActorFactoryBlueprint.h"
#define LOCTEXT_NAMESPACE "FZuyiModule"

void FZuyiModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	IPlacementModeModule& PlacementModeModule = IPlacementModeModule::Get();
	// custom item 1 in Basic Section
	UBlueprint* BpZuyi = Cast<UBlueprint>(FSoftObjectPath(TEXT("/Zuyi/BP_Zuyi.BP_Zuyi")).TryLoad());
	if (BpZuyi == nullptr)
	{
		return;
	}

	const FPlacementCategoryInfo* InfoBasic = IPlacementModeModule::Get().GetRegisteredPlacementCategory(FLevelEditorOutlinerBuiltInCategories::Basic());
	if (GEditor)
	{
		FPlaceableItem* BPPlacement = new FPlaceableItem(
			*UActorFactoryBlueprint::StaticClass(),
			FAssetData(BpZuyi, true),
			FName("ClassThumbnail.Cube"),
			FName("ClassIcon.Cube"),
			TOptional<FLinearColor>(),
			TOptional<int32>(),
			LOCTEXT("Zuyi ", "Zuyi")
		);
		IPlacementModeModule::Get().RegisterPlaceableItem(InfoBasic->UniqueHandle, MakeShareable(BPPlacement));
	}	
		
}

void FZuyiModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FZuyiModule, Zuyi)