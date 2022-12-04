#pragma once

#include "ATask.h"

class AConsoleMessage : public ATask
{
	COMPONENT_DEFINE(AConsoleMessage, ATask)
	PROP_PARAM(String, message)
public:
	void run() override;
};