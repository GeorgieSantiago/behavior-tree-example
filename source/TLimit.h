#pragma once

#include <Unigine.h>
#include "ATask.h"

class TLimit : public ATask
{
	COMPONENT_DEFINE(TLimit, ATask)
	PROP_PARAM(Int, limit, 1)
private:
	int count = 0;
	bool is_repeating = false;
public:
	void run() override;
	void child_success() override {};
	void child_fail() override {};
};