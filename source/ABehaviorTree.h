#pragma once

#include "ATask.h"

class ABehaviorTree : public ATask
{
	COMPONENT_DEFINE(ABehaviorTree, ATask)
	COMPONENT_UPDATE(update)
	PROP_PARAM(Node, target)
public:
	void post_init();
protected:
	void update();
};
