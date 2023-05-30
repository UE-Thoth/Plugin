// © 2023 Kaya Adrian.

#pragma once

#include "IThothModule.h"


#define LOCTEXT_NAMESPACE "ThothModule"

class FThothModule : public IThothModule
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

#undef LOCTEXT_NAMESPACE
