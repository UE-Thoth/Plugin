// © 2023 Kaya Adrian.

using UnrealBuildTool;


public class Thoth : ModuleRules
{
	public Thoth(ReadOnlyTargetRules target) : base(target)
	{
		Type = ModuleType.CPlusPlus;
		PCHUsage = PCHUsageMode.NoPCHs;
		IWYUSupport = IWYUSupport.Full;
		CppStandard = CppStandardVersion.Cpp20;
		
		bUseUnity = false;
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
