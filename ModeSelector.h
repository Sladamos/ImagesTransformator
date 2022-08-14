#pragma once
#include <vector>
#include <string>
#include "Transformator.h"
class ModeSelector
{
public:
	static std::string selectNewMode(const std::string& currentMode, const std::vector<std::string>& transformators);
private:
	static void printSelector(const std::vector<std::string>& transformators);
	static std::string updateMode(const std::string& currentMode, const std::vector<std::string>& transformators);
	static std::string readModeFromInput(const std::vector<std::string>& transformators);
};