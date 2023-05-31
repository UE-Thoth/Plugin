// © 2023 Kaya Adrian.

#pragma once

#include "ThothFutureObject.generated.h"

class UThothAsyncLibrary;


#define LOCTEXT_NAMESPACE "ThothFutureObject"

UCLASS(Blueprintable, BlueprintType, DisplayName = "Thoth Future Object")
class THOTH_API UThothFutureObject : public UObject
{
	GENERATED_BODY()

	UPROPERTY(Transient, NonTransactional)
	TWeakObjectPtr<UObject> InternalFuture;
	
public:
	UE_NODISCARD_CTOR
	UThothFutureObject() noexcept;
	
	friend UThothAsyncLibrary;
};

#undef LOCTEXT_NAMESPACE
