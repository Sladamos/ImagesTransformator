#include "ProgramEngine.h"

ProgramEngine::ProgramEngine(std::shared_ptr<Menu> menu, std::shared_ptr<Notifier> programExitedNotifier)
{
	this->menu = menu;
	auto execute = [this]() { this->turnOffProgram(); };
	programExitedNotifier->notified += execute;
}

void ProgramEngine::startProgram()
{
	isProgramLaunched = true;
	while (isProgramLaunched)
	{
		menu->printOptions();
		menu->selectAndExecuteOption();
	}
}

void ProgramEngine::turnOffProgram()
{
	isProgramLaunched = false;
}