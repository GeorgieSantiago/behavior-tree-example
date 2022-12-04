#pragma once

#include <Unigine.h>
#include "ATask.h"

class TAlwaysSucceed : public ATask
{
	COMPONENT_DEFINE(TAlwaysSucceed, ATask)
public:
	void run() override;
	void child_success() override {};
	void child_fail() override {};
};