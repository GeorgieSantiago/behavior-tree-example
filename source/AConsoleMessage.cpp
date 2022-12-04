#include "AConsoleMessage.h"
#include <string>

REGISTER_COMPONENT(AConsoleMessage)

void AConsoleMessage::run()
{
	if (this->state == TaskState::RUNNING)
	{
		Console::message(
			std::string("\n")
			.append(message)
			.c_str()
		);
	}
	this->success();
}