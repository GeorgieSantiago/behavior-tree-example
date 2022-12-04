#include "TAlwaysSucceed.h"

REGISTER_COMPONENT(TAlwaysSucceed)

void TAlwaysSucceed::run()
{
	if (child_task.size() > 0)
	{
		child_task[0]->running();
	}
	this->success();
}