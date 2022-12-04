#include "ATask.h"

void ATask::running()
{
	this->state = TaskState::RUNNING;
	if (control_ptr != nullptr)
	{
		control_ptr->child_running();
	}
}

void ATask::success()
{
	this->state = TaskState::SUCCEEDED;
	if (control_ptr != nullptr)
	{
		control_ptr->child_success();
	}
}

void ATask::fail()
{
	this->state = TaskState::FAILED;
	if (control_ptr != nullptr)
	{
		control_ptr->child_fail();
	}
}

void ATask::cancel()
{
	if (this->state == TaskState::RUNNING)
	{
		this->state = TaskState::CANCELLED;
		for (int i = 0; i < child_task.size(); i++)
		{
			child_task[i]->cancel();
		}
	}
}

void ATask::start()
{
	this->state = TaskState::RUNNING;
	for (int i = 0; i < child_task.size();i++)
	{
		ATask* child = child_task[i];
		child->control_ptr = this;
		child->tree_ptr = this->tree_ptr;
		child->start();
	}
}

void ATask::reset()
{
	this->cancel();
	this->state = TaskState::FRESH;
}

void ATask::init()
{
	for (int i = 0; i < node->getNumChildren(); i++)
	{
		ATask* task = getComponent<ATask>(node->getChild(i));
		if (task != nullptr)
		{
			child_task.append(task);
		}
	}
	this->start();
	this->post_init();
	this->propagate_tree();
}

void ATask::propagate_tree()
{
	if (this->tree_ptr != nullptr)
	{
		for (int i = 0; i < child_task.size(); i++)
		{
			child_task[i]->tree_ptr = this->tree_ptr;
		}
	}
}

NodePtr ATask::get_node()
{
	return node;
}