// © 2023 Kaya Adrian.

#pragma once

#include "Async/Async.h"

#include "ThothAsyncExecutionMode.generated.h"


#define LOCTEXT_NAMESPACE "ThothAsyncExecutionMode"

// Represents every priority type that can be assigned to a thread
UENUM(BlueprintType, Category = "Thoth|Async", DisplayName = "Thoth Async Execution Mode", meta = (
	Keywords = "Thoth Async Execution Mode"
))
enum class EThothAsyncExecutionMode : uint8
{
	// Execute in Task Graph (for short running tasks)
	TaskGraph = EAsyncExecution::TaskGraph UMETA(DisplayName = "Task Graph"),
	// Execute in Task Graph on the main thread (for short running tasks)
	TaskGraphMainThread = EAsyncExecution::TaskGraphMainThread UMETA(DisplayName = "Task Graph Main Thread"),
	// Execute in separate thread if supported (for long running tasks)
	Thread = EAsyncExecution::Thread UMETA(DisplayName = "Thread"),
	// Execute in separate thread if supported or supported post fork (for long running tasks)
	ThreadIfForkSafe = EAsyncExecution::ThreadIfForkSafe UMETA(DisplayName = "Thread If Fork Safe"),
	// Execute in global queued thread pool
	ThreadPool = EAsyncExecution::ThreadPool UMETA(DisplayName = "Thread Pool"),
#if WITH_EDITOR
	// [EDITOR ONLY] Execute in large global queued thread pool
	LargeThreadPool = EAsyncExecution::LargeThreadPool UMETA(DisplayName = "Large Thread Pool"),
#endif
};


namespace ThothEnums
{
	UE_NODISCARD
	static FORCEINLINE CONSTEXPR EAsyncExecution Cast(const EThothAsyncExecutionMode ExecutionMode) noexcept
	{ return static_cast<EAsyncExecution>(ExecutionMode); }
	
	UE_NODISCARD
	static FORCEINLINE CONSTEXPR EThothAsyncExecutionMode Cast(const EAsyncExecution ExecutionMode) noexcept
	{ return static_cast<EThothAsyncExecutionMode>(ExecutionMode); }
}

#undef LOCTEXT_NAMESPACE
