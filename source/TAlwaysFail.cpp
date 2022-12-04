#include "TAlwaysFail.h"

REGISTER_COMPONENT(TAlwaysFail)

void TAlwaysFail::run()
{
	if (child_task.size() > 0)
	{
		child_task[0]->running();
	}
	this->fail();
}