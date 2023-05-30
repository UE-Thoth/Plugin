// © 2023 Kaya Adrian.

#include "Macros/ThothMacrosLog.h"

#include "Settings/ThothSettingsDev.h"


#define LOCTEXT_NAMESPACE "ThothMacrosLog"

DEFINE_LOG_CATEGORY(LogThoth)

namespace
{
	UE_NODISCARD
	FORCEINLINE bool AreLogsEnabled() noexcept { return GetDefault<UThothSettingsDev>()->IsLogThothEnabled(); }
}
const IsLogThothEnabledCheck IsLogThothEnabled = &AreLogsEnabled;

#undef LOCTEXT_NAMESPACE
