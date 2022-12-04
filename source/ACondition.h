#pragma once

#include "ATask.h"

class ACondition : public ATask
{
	COMPONENT_DEFINE(ACondition, ATask)
public:
	void run() override;
	virtual bool check() { return false; }
};
