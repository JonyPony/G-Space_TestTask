// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class G_Space_TestTask : ModuleRules
{
	public G_Space_TestTask(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
