// © 2023 Kaya Adrian.

#pragma once

#include "Engine/DeveloperSettingsBackedByCVars.h"

#include "ThothSettingsBase.generated.h"


#define LOCTEXT_NAMESPACE "ThothSettingsBase"

/**
 * @brief Base class for Thoth settings
 */
UCLASS(Abstract, MinimalAPI, Config = "Thoth", Blueprintable, BlueprintType, DisplayName = "Thoth Base Settings")
class UThothSettingsBase : public UDeveloperSettingsBackedByCVars
{
	GENERATED_BODY()
	
public:
	UE_NODISCARD_CTOR
	UThothSettingsBase() noexcept;
};

#undef LOCTEXT_NAMESPACE
