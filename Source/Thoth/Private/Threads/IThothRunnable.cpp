// © 2023 Kaya Adrian.

#include "Threads/IThothRunnable.h"

#include "Threads/ThothRunnableNative.h"


#define LOCTEXT_NAMESPACE "IThothRunnable"

void FRunnableDeleter::operator()(FThothRunnableNative* const Runnable) const noexcept
{
	if (Runnable)
	{
		Runnable->Stop();
	}
}

IThothRunnable::IThothRunnable() noexcept : NativeRunnable(nullptr)
{
}

bool IThothRunnable::Init_Implementation() noexcept
{
	return true;
}

void IThothRunnable::Stop_Implementation() noexcept
{
}

void IThothRunnable::Exit_Implementation() noexcept
{
}

#undef LOCTEXT_NAMESPACE
