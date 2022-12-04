#pragma once

#include <Unigine.h>
#include "ATask.h"

class TRepeat : public ATask
{
public:
	void run() override;
	void child_success() override {};
	void child_fail() override {};
};