//Author: Slawomir Adamowicz
#include "ConsoleMenu.h"
#include "ProgramEngine.h"
#include "Config.h"
#include "Notifier.h"

int main()
{
	try
	{
		auto programExitedNotifier = std::shared_ptr<Notifier>(new Notifier());
		Config appConfig(std::string("config.json"));
		std::shared_ptr<Menu> menu = std::shared_ptr<Menu>(new ConsoleMenu(appConfig, programExitedNotifier));
		ProgramEngine engine(menu, programExitedNotifier);
		engine.startProgram();
		return 0;
	}
	catch (const std::exception&)
	{
		return 404;
	}
}