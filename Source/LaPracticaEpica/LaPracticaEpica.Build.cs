// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LaPracticaEpica : ModuleRules
{
	public LaPracticaEpica(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
