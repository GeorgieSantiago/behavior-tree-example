#include "ACondition.h"

void ACondition::run()
{
	if (check())
	{
		this->child_task[0]->run();
		this->success();
	}
	else {
		this->fail();
	}
}