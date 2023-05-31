// © 2023 Kaya Adrian.

#include "Async/ThothAsyncLibrary.h"

#include "Async/ThothFutureObject.h"


#define LOCTEXT_NAMESPACE "ThothAsyncLibrary"

UThothFutureObject* UThothAsyncLibrary::K2_ExecuteAsync(
	UObject* const InputObject,
	UObject* const OutputObject,
	const EThothAsyncExecutionMode ExecutionMode,
	const FThothAsyncCallback& Callback,
	const FThothAsyncCompletionCallback& CompletionCallback
) noexcept
{
	auto* const FutureObject = NewObject<UThothFutureObject>();
	Async(
		ThothEnums::Cast(ExecutionMode),
		[InputObject, OutputObject, Callback, FutureObject]
		{
			FutureObject->InternalFuture = LIKELY(Callback.ExecuteIfBound(InputObject, OutputObject)) ?
				OutputObject : nullptr;
		},
		[CompletionCallback] { return CompletionCallback.ExecuteIfBound(); }
	);
	return FutureObject;
}

#undef LOCTEXT_NAMESPACE
