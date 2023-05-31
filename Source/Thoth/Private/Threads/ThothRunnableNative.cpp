// © 2023 Kaya Adrian.

#include "Threads/ThothRunnableNative.h"


#define LOCTEXT_NAMESPACE "ThothRunnableNative"

FThothRunnableNative::FThothRunnableNative(const TScriptInterface<IThothRunnable>& Runnable) noexcept :
RunnableObject(Runnable.GetObject())
{
	if (LIKELY(Runnable))
	{
		Runnable->NativeRunnable.Reset(this);
	}
}

bool FThothRunnableNative::Init()
{
	return LIKELY(RunnableObject.IsValid(false, true)) && IThothRunnable::Execute_Init(RunnableObject.Get());
}

uint32 FThothRunnableNative::Run()
{
	return LIKELY(RunnableObject.IsValid(false, true)) ? IThothRunnable::Execute_Run(RunnableObject.Get()) : 0U;
}

void FThothRunnableNative::Stop()
{
	if (LIKELY(RunnableObject.IsValid(false, true)))
	{
		IThothRunnable::Execute_Stop(RunnableObject.Get());
	}
}

void FThothRunnableNative::Exit()
{
	if (LIKELY(RunnableObject.IsValid(false, true)))
	{
		IThothRunnable::Execute_Exit(RunnableObject.Get());
	}
}

#undef LOCTEXT_NAMESPACE
