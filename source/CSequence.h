#pragma once

#include "ATask.h"

class CSequence : public ATask
{
	COMPONENT_DEFINE(CSequence, ATask)
public:
	int count = 0;
	void run() override;
	void child_success() override;
	void child_fail() override;
};