#pragma once
#include <map>
#include <string>
#include "Transformator.h"
class ModeSelector
{
public:
	static std::string selectNewMode(const std::string& currentMode, const std::map<std::string, Transformator*>& transformators);
private:
	static void printSelector(const std::map<std::string, Transformator*>& transformators);
	static std::string updateMode(const std::string& currentMode, const std::map<std::string, Transformator*>& transformators);
	static std::string readModeFromInput(const std::map<std::string, Transformator*>& transformators);
};

