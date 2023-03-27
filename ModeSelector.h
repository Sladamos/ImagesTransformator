#pragma once
#include <vector>
#include <string>
#include "Transformator.h"
class ModeSelector
{
public:
	ModeSelector(const std::string& currentMode, const std::vector<std::string>& modes);
	std::string selectNewMode();
private:
	virtual void printModes() = 0;
	virtual std::string readMode() = 0;
	std::string updateMode();
};