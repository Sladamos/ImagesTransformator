//Author: Slawomir Adamowicz
#include "ConsoleMenu.h"
#include "ProgramEngine.h"

int main()
{
	std::shared_ptr<Menu> menu = std::shared_ptr<Menu>(new ConsoleMenu());
	ProgramEngine engine(menu);
	engine.startProgram();
	return 0;
}