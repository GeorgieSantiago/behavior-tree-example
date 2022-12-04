#include "TInvert.h"

REGISTER_COMPONENT(TInvert)

void TInvert::run()
{
	child_task[0]->run();
	this->running();
}