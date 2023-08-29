#include <fstream>
#include "Config.h"

using json = nlohmann::json;

Config::Config(const std::string& path)
{
	std::ifstream f(path);
	config = json::parse(f);
}

Config::Config(const nlohmann::json& config) : config(config)
{
}
