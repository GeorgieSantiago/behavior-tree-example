#include "CSequence.h"

REGISTER_COMPONENT(CSequence)

void CSequence::run()
{
	child_task[count]->run();
	this->running();
}

void CSequence::child_success()
{
	count++;
	if (count >= child_task.size())
	{
		count = 0;
		this->success();
	}
}

void CSequence::child_fail()
{
	count = 0;
	this->fail();
}
