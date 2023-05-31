// © 2023 Kaya Adrian.

#pragma once

#include "ThothRunnableThreadPriorityType.generated.h"


#define LOCTEXT_NAMESPACE "ThothRunnableThreadPriorityType"

// Represents every priority type that can be assigned to a thread
UENUM(BlueprintType, Category = "Thoth|Runnable", DisplayName = "Thoth Runnable Thread Priority Type", meta = (
	Keywords = "Thoth Runnable Thread Priority Type"
))
enum class EThothRunnableThreadPriorityType : uint8
{
	// TPri_Normal
	Normal = TPri_Normal UMETA(DisplayName = "Normal"),
	// TPri_AboveNormal
	AboveNormal = TPri_AboveNormal UMETA(DisplayName = "Above Normal"),
	// TPri_BelowNormal
	BelowNormal = TPri_BelowNormal UMETA(DisplayName = "Below Normal"),
	// TPri_Highest
	Highest = TPri_Highest UMETA(DisplayName = "Highest"),
	// TPri_Lowest
	Lowest = TPri_Lowest UMETA(DisplayName = "Lowest"),
	// TPri_SlightlyBelowNormal
	SlightlyBelowNormal = TPri_SlightlyBelowNormal UMETA(DisplayName = "Slightly Below Normal"),
	// TPri_TimeCritical
	TimeCritical = TPri_TimeCritical UMETA(DisplayName = "Time Critical"),
	// Number of types
	Num = TPri_Num UMETA(Hidden, DisplayName = "Types Count")
};


namespace ThothEnums
{
	UE_NODISCARD
	static FORCEINLINE CONSTEXPR EThreadPriority Cast(const EThothRunnableThreadPriorityType PriorityType) noexcept
	{ return static_cast<EThreadPriority>(PriorityType); }
	
	UE_NODISCARD
	static FORCEINLINE CONSTEXPR EThothRunnableThreadPriorityType Cast(const EThreadPriority PriorityType) noexcept
	{ return static_cast<EThothRunnableThreadPriorityType>(PriorityType); }
}

#undef LOCTEXT_NAMESPACE
