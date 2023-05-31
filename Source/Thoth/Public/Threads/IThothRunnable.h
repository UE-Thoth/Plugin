// © 2023 Kaya Adrian.

#pragma once

#include "HAL/Runnable.h"
#include "UObject/Interface.h"

#include "IThothRunnable.generated.h"

class FThothRunnableNative;


#define LOCTEXT_NAMESPACE "IThothRunnable"

struct FRunnableDeleter
{
	void operator()(FThothRunnableNative* Runnable) const noexcept;
};


UINTERFACE(MinimalAPI, Blueprintable, BlueprintType, DisplayName = "Thoth Runnable")
class UThothRunnable : public UInterface
{
	GENERATED_BODY()
};


class THOTH_API IThothRunnable
{
	GENERATED_BODY()
	
	TUniquePtr<FThothRunnableNative, FRunnableDeleter> NativeRunnable;
	
public:
	UE_NODISCARD_CTOR
	IThothRunnable() noexcept;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Thoth|Runnable")
	bool Init();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Thoth|Runnable")
	int32 Run();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Thoth|Runnable")
	void Stop();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Thoth|Runnable")
	void Exit();
	
protected:
	virtual bool Init_Implementation() noexcept;
	
	virtual int32 Run_Implementation() noexcept
	PURE_VIRTUAL(IThothRunnable::Run, return 0;);
	
	virtual void Stop_Implementation() noexcept;
	
	virtual void Exit_Implementation() noexcept;
	
	friend FThothRunnableNative;
};

#undef LOCTEXT_NAMESPACE
