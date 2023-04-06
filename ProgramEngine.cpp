#include "ProgramEngine.h"

ProgramEngine::ProgramEngine(std::shared_ptr<Menu> menu)
{
	this->menu = menu;
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
