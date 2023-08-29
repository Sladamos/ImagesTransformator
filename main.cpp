//Author: Slawomir Adamowicz
#include "ConsoleMenu.h"
#include "ProgramEngine.h"
#include "json.hpp"
#include <fstream>

using json = nlohmann::json;
json readProgramConfig();

int main()
{
	json config = readProgramConfig();
	std::shared_ptr<Menu> menu = std::shared_ptr<Menu>(new ConsoleMenu());
	ProgramEngine engine(menu);
	engine.startProgram();
	return 0;
}

json readProgramConfig()
{
	try
	{
		std::ifstream f("config.json");
		json config = json::parse(f);
		return config;
	}
	catch (const std::exception&)
	{
		exit(400);
	}
}