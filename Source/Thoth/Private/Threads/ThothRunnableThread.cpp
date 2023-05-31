// © 2023 Kaya Adrian.

#include "Threads/ThothRunnableThread.h"

#include "Threads/ThothRunnableNative.h"


#define LOCTEXT_NAMESPACE "ThothRunnableThread"

void FThreadDeleter::operator()(FRunnableThread* const RunnableThread) const noexcept
{
	if (RunnableThread && RunnableThread->GetRunnableThread())
	{
		RunnableThread->Kill(false);
	}
}

UThothRunnableThread::UThothRunnableThread() noexcept : InternalThread(nullptr), Runnable(nullptr)
{
}

UThothRunnableThread* UThothRunnableThread::CreateThread(
	const TScriptInterface<IThothRunnable>& InRunnable,
	const FString& ThreadName,
	const int64 StackSize,
	const EThothRunnableThreadPriorityType ThreadPriority,
	const int64 ThreadAffinityMask,
	const int32 CreateFlags
) noexcept
{
	if (InRunnable == nullptr)
		return nullptr;
	
	auto* const Thread = NewObject<UThothRunnableThread>(InRunnable.GetObject());
	Thread->Runnable = InRunnable;
	
	Thread->InternalThread.Reset(FRunnableThread::Create(
		new FThothRunnableNative(Thread->Runnable),
		*ThreadName,
		static_cast<uint32>(StackSize),
		ThothEnums::Cast(ThreadPriority),
		ThreadAffinityMask == 0LL ? FPlatformAffinity::GetNoAffinityMask() : ThreadAffinityMask,
		static_cast<EThreadCreateFlags>(CreateFlags)
	));
	return Thread;
}

bool UThothRunnableThread::Kill(const bool bShouldWait) noexcept
{
	if (!InternalThread.IsValid() || !InternalThread->Kill(bShouldWait))
		return false;
	
	Runnable = nullptr;
	return true;
}

#undef LOCTEXT_NAMESPACE
