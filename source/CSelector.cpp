#include "CSelector.h"

REGISTER_COMPONENT(CSelector)

void CSelector::run()
{
	child_task[count]->run();
	this->running();
}

void CSelector::child_success()
{
	count = 0;
	this->success();
}

void CSelector::child_fail()
{
	count++;
	if (count > child_task.size())
	{
		this->fail();
		return;
	}
	this->running();
}