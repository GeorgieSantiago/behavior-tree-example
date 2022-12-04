#pragma once

#include <Unigine.h>
#include "ATask.h"

class TUntilFail : public ATask
{
public:
	void run() override;
	void child_success() override {};
	void child_fail() override {};
};