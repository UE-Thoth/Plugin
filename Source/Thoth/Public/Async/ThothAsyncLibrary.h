// © 2023 Kaya Adrian.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ThothAsyncExecutionMode.h"

#include "ThothAsyncLibrary.generated.h"

class UThothFutureObject;


#define LOCTEXT_NAMESPACE "ThothAsyncLibrary"

DECLARE_DYNAMIC_DELEGATE_TwoParams(FThothAsyncCallback, UObject*, InputObject, UObject*, OutputObject);
DECLARE_DYNAMIC_DELEGATE(FThothAsyncCompletionCallback);


UCLASS(Abstract, Blueprintable, BlueprintType, DisplayName = "Thoth Async Library")
class THOTH_API UThothAsyncLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	static FORCEINLINE UThothFutureObject* ExecuteAsync(
		UObject* const InputObject,
		UObject* const OutputObject,
		const EThothAsyncExecutionMode ExecutionMode,
		const FThothAsyncCallback& Callback,
		const FThothAsyncCompletionCallback& CompletionCallback = FThothAsyncCompletionCallback()
	) noexcept
	{ return K2_ExecuteAsync(InputObject, OutputObject, ExecutionMode, Callback, CompletionCallback); }
	
protected:
	UFUNCTION(BlueprintCallable, Category = "Thoth|Async", DisplayName = "Execute Async", meta = (
		AdvancedDisplay = "4",
		AutoCreateRefTerm = "CompletionCallback"
	))
	static UPARAM(DisplayName = "Future Output Object") UThothFutureObject* K2_ExecuteAsync(
		UObject* InputObject,
		UObject* OutputObject,
		EThothAsyncExecutionMode ExecutionMode,
		const FThothAsyncCallback& Callback,
		const FThothAsyncCompletionCallback& CompletionCallback
	) noexcept;
};

#undef LOCTEXT_NAMESPACE
