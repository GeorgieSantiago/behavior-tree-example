#pragma once

#include "ACondition.h"

class BIsEnabled : public ACondition
{
	COMPONENT_DEFINE(BIsEnabled, ACondition)
	PROP_PARAM(Toggle, is_enabled)
public:
	bool check() override { return is_enabled; }
};
