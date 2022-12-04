#pragma once

#include <Unigine.h>
#include "ATask.h"

class TInvert : public ATask
{
	COMPONENT_DEFINE(TInvert, ATask)
public:
	void run() override;
	void child_success() override { this->fail(); };
	void child_fail() override { this->success(); };
};