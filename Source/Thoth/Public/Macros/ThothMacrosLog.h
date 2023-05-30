// © 2023 Kaya Adrian.

#pragma once

#include "Logging/LogMacros.h"


#define LOCTEXT_NAMESPACE "ThothMacrosLog"

#define THOTH_LOG(Verbosity, Format, ...) THOTH_CLOG(true, Verbosity, Format, ##__VA_ARGS__)

#define THOTH_CLOG(Condition, Verbosity, Format, ...) \
UE_CLOG(IsLogThothEnabled() && (Condition), LogAtum, Verbosity, Format, ##__VA_ARGS__)

DECLARE_LOG_CATEGORY_EXTERN(LogThoth, Log, All)

using IsLogThothEnabledCheck = bool (*)();
extern const IsLogThothEnabledCheck IsLogThothEnabled;

#undef LOCTEXT_NAMESPACE
