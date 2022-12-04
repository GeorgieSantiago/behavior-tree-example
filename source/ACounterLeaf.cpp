#include "ACounterLeaf.h"

REGISTER_COMPONENT(ACounterLeaf)

void ACounterLeaf::run()	
{
	if (this->state == TaskState::RUNNING)
	{
		count += 1;
		if (count <= max_count)
		{
			Log::message(std::to_string(count).c_str());
			this->running();
		}
		else {
			count = 0;
			this->success();
		}
	}
}