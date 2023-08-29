//Author: Slawomir Adamowicz
#include "ConsoleMenu.h"
#include "ProgramEngine.h"
#include "Config.h"

int main()
{
	try
	{
		Config appConfig(std::string("config.json"));
		std::shared_ptr<Menu> menu = std::shared_ptr<Menu>(new ConsoleMenu(appConfig));
		ProgramEngine engine(menu);
		engine.startProgram();
		return 0;
	}
	catch (const std::exception&)
	{
		return 404;
	}
}