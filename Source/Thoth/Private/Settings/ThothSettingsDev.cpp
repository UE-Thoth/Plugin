// © 2023 Kaya Adrian.

#include "Settings/ThothSettingsDev.h"

#include "HAL/IConsoleManager.h"


#define LOCTEXT_NAMESPACE "ThothSettingsDev"

UThothSettingsDev::UThothSettingsDev() noexcept : bLogThothEnabled(true)
{
	SectionName = TEXT("Thoth - Development");
	
	LoadConfig();
	IConsoleManager::Get().RegisterConsoleVariableRef(
		TEXT("thoth.Dev.EnableLogThoth"),
		bLogThothEnabled,
		TEXT("Controls whether or not Thoth is able to print messages to LogThoth.")
	);
}

#if WITH_EDITOR
FText UThothSettingsDev::GetSectionText() const
{
	return LOCTEXT("ThothSettingsDevSectionText", "Development");
}

FText UThothSettingsDev::GetSectionDescription() const
{
	return LOCTEXT("ThothSettingsDevSectionDescription", "Thoth settings for development purposes");
}
#endif

#undef LOCTEXT_NAMESPACE
