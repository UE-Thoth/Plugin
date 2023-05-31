// © 2023 Kaya Adrian.

#pragma once

#include "ThothRunnableThreadCreateFlags.generated.h"


#define LOCTEXT_NAMESPACE "ThothRunnableThreadCreateFlags"

// Represents thread creation flags
UENUM(BlueprintType, Category = "Thoth|Runnable", DisplayName = "Thoth Runnable Thread Create Flags", meta = (
	Bitflags,
	Keywords = "Thoth Runnable Thread Create Flags",
	UseEnumValuesAsMaskValuesInEditor
))
enum class EThothRunnableThreadCreateFlags : uint8
{
	None = EThreadCreateFlags::None UMETA(Hidden, DisplayName = "None"), // None
	SmtExclusive = EThreadCreateFlags::SMTExclusive UMETA(DisplayName = "SMT Exclusive") // SMTExclusive
};


namespace ThothEnums
{
	UE_NODISCARD
	static FORCEINLINE CONSTEXPR EThreadCreateFlags Cast(const EThothRunnableThreadCreateFlags CreateFlags) noexcept
	{ return static_cast<EThreadCreateFlags>(CreateFlags); }
	
	UE_NODISCARD
	static FORCEINLINE CONSTEXPR EThothRunnableThreadCreateFlags Cast(const EThreadCreateFlags CreateFlags) noexcept
	{ return static_cast<EThothRunnableThreadCreateFlags>(CreateFlags); }
}

#undef LOCTEXT_NAMESPACE
