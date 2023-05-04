#include "ProgramEngine.h"

ProgramEngine::ProgramEngine(std::shared_ptr<Menu> menu)
{
	this->menu = menu;
	auto execute = [this]() { this->turnOffProgram(); };
	menu->exitProgram += execute;
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