#pragma once

#include <Unigine.h>

using namespace Unigine;

enum TaskState {
	FRESH, // This is a new task and it has not been reset
	RUNNING, // The task is currently running
	FAILED, // The task has failed to complete
	SUCCEEDED, // The task has completed
	CANCELLED // The task was interrupted
};

class ATask : public ComponentBase
{
	COMPONENT_DEFINE(ATask, ComponentBase)
	COMPONENT_INIT(init)
	PROP_PARAM(Node, target)
private:
	ATask *control_ptr = nullptr;
	//This may be a different class but putting it as
	//this for now. 
	//Guard guard_ptr;
public:
	NodePtr get_node();
	ATask* tree_ptr = nullptr;
	Vector<ATask*> child_task;
	TaskState state;
	void running();
	void success();
	void fail();
	void cancel();
	virtual void post_init() {};
	virtual void run() {};
	virtual void child_success() {};
	virtual void child_fail() {};
	virtual void child_running() {};
protected:
	void init();
	void start();
	void reset();
private:
	void propagate_tree();
};

