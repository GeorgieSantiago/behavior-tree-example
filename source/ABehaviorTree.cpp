#include "ABehaviorTree.h"

REGISTER_COMPONENT(ABehaviorTree)

void ABehaviorTree::update()
{
	//
	for (int i = 0; i < child_task.size(); i++)
	{
		child_task[i]->run();
	}
}

void ABehaviorTree::post_init()
{
	for (int i = 0; i < child_task.size(); i++)
	{
		child_task[i]->tree_ptr = this;
	}
}