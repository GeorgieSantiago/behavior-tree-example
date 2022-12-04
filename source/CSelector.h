#pragma once

#include "ATask.h"

class CSelector : public ATask
{
	COMPONENT_DEFINE(CSelector, ATask)
public:
	int count = 0;
	void run() override;
	void child_success() override;
	void child_fail() override;
};