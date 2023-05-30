// © 2023 Kaya Adrian.

#include "ThothModule.h"

#include "Macros/ThothMacrosLog.h"


#define LOCTEXT_NAMESPACE "ThothModule"

void FThothModule::StartupModule()
{
	UE_LOG(LogThoth, Warning, TEXT("Loaded Thoth plugin!"));
}

void FThothModule::ShutdownModule()
{
	UE_LOG(LogThoth, Warning, TEXT("Unloaded Thoth plugin!"))
}

IMPLEMENT_MODULE(FThothModule, Thoth)

#undef LOCTEXT_NAMESPACE
