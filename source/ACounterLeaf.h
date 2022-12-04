#pragma once

#include "ATask.h"
#include <string>

class ACounterLeaf : public ATask
{
	COMPONENT_DEFINE(ACounterLeaf, ATask)
	PROP_PARAM(Int, max_count, 5)
public:
	int count = 0;
	void run() override;
};

