// © 2023 Kaya Adrian.

#pragma once

#include "ThothSettingsBase.h"

#include "ThothSettingsDev.generated.h"


#define LOCTEXT_NAMESPACE "ThothSettingsDev"

/**
 * @brief Thoth settings for development purposes
 */
UCLASS(MinimalAPI, BlueprintType, DisplayName = "Thoth Dev Settings")
class UThothSettingsDev : public UThothSettingsBase
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, DisplayName = "Enable LogThoth", meta = (
		AllowPrivateAccess,
		ConsoleVariable = "thoth.Dev.EnableLogThoth"
	))
	bool bLogThothEnabled;
	
public:
	UE_NODISCARD_CTOR
	UThothSettingsDev() noexcept;
	
#if WITH_EDITOR
	UE_NODISCARD
	virtual FText GetSectionText() const override;
	
	UE_NODISCARD
	virtual FText GetSectionDescription() const override;
#endif
	
	UE_NODISCARD
	FORCEINLINE bool IsLogThothEnabled() const noexcept { return bLogThothEnabled; }
	
	UE_NODISCARD
	FORCEINLINE void SetLogThothEnabled(const bool bValue) noexcept { bLogThothEnabled = bValue; }
};

#undef LOCTEXT_NAMESPACE
