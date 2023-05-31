// © 2023 Kaya Adrian.

#pragma once

#include "IThothRunnable.h"


#define LOCTEXT_NAMESPACE "ThothRunnableNative"

class THOTH_API FThothRunnableNative : public FRunnable
{
	TWeakObjectPtr<UObject> RunnableObject;
	
public:
	UE_NODISCARD_CTOR
	explicit FThothRunnableNative(const TScriptInterface<IThothRunnable>& Runnable) noexcept;
	
	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Stop() override;
	virtual void Exit() override;
	
	FORCEINLINE TWeakObjectPtr<const UObject> GetRunnableObject() const noexcept { return RunnableObject; }
	FORCEINLINE TWeakObjectPtr<UObject> GetRunnableObject() noexcept { return RunnableObject; }
};

#undef LOCTEXT_NAMESPACE
