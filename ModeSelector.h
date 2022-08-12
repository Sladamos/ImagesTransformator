#pragma once
#include <string>
class ModeSelector
{
public:
	static std::string selectNewMode(const std::string& currentMode);
private:
	static void printSelector();
	static std::string updateMode(const std::string& currentMode);
};

