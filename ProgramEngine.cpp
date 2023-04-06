#include "ProgramEngine.h"

ProgramEngine::ProgramEngine()
{
}

void ProgramEngine::startProgram()
{
	isProgramLaunched = true;
	while (isProgramLaunched)
	{
		menu->print();
		menu->handleOption();
	}
}
