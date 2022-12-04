#pragma once

#include <Unigine.h>
#include "ATask.h"

class TAlwaysFail : public ATask
{
	COMPONENT_DEFINE(TAlwaysFail, ATask)
public:
	void run() override;
	void child_success() override {};
	void child_fail() override {};
};