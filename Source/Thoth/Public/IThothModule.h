// © 2023 Kaya Adrian.

#pragma once

#include "Modules/ModuleManager.h"


#define LOCTEXT_NAMESPACE "IThothModule"

class THOTH_API IThothModule : public IModuleInterface
{
public:
	static const FName ModuleName;
	
	UE_NODISCARD
	static FORCEINLINE bool IsModuleLoaded() noexcept { return FModuleManager::Get().IsModuleLoaded(ModuleName); }
	
	UE_NODISCARD
	static FORCEINLINE IThothModule& GetModule() { return FModuleManager::LoadModuleChecked<IThothModule>(ModuleName); }
};

#undef LOCTEXT_NAMESPACE
