// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;


public class Thoth : ModuleRules
{
	public Thoth(ReadOnlyTargetRules target) : base(target)
	{
		Type = ModuleType.CPlusPlus;
		PCHUsage = PCHUsageMode.NoPCHs;
		CppStandard = CppStandardVersion.Cpp20;
		
		bUseUnity = false;
		bEnforceIWYU = true;
		bUsePrecompiled = false;
		
		PublicDependencyModuleNames.AddRange(new[]
		{
			"Core",
			"CoreUObject",
			"Engine"
		});
		
		PrivateDependencyModuleNames.AddRange(new[]
		{
			"DeveloperSettings"
		});
	}
}
