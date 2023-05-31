// © 2023 Kaya Adrian.

#pragma once

#include "HAL/RunnableThread.h"
#include "IThothRunnable.h"
#include "ThothRunnableThreadPriorityType.h"

#include "ThothRunnableThread.generated.h"


#define LOCTEXT_NAMESPACE "ThothRunnableThread"

struct FThreadDeleter
{
	void operator()(FRunnableThread* RunnableThread) const noexcept;
};


UCLASS(Blueprintable, BlueprintType, DisplayName = "Thoth Runnable Thread")
class THOTH_API UThothRunnableThread : public UObject
{
	GENERATED_BODY()
	
	TUniquePtr<FRunnableThread, FThreadDeleter> InternalThread;
	
	UPROPERTY()
	TScriptInterface<IThothRunnable> Runnable;
	
public:
	UE_NODISCARD_CTOR
	UThothRunnableThread() noexcept;
	
	UFUNCTION(BlueprintCallable, Category = "Thoth|Runnable", meta = (
		Keywords = "Thoth Create In Runnable Thread Name Stack Size Priority Affinity Mask Flags"
	))
	static UThothRunnableThread* CreateThread(
		const TScriptInterface<IThothRunnable>& InRunnable,
		const FString& ThreadName,
		int64 StackSize = 0LL,
		EThothRunnableThreadPriorityType ThreadPriority = EThothRunnableThreadPriorityType::Normal,
		int64 ThreadAffinityMask = 0LL,
		UPARAM(meta = (Bitmask, BitmaskEnum = "EThothRunnableThreadCreateFlags")) int32 CreateFlags = 0
	) noexcept;
	
	UFUNCTION(BlueprintCallable, Category = "Thoth|Runnable")
	bool Kill(bool bShouldWait = true) noexcept;
};

#undef LOCTEXT_NAMESPACE
