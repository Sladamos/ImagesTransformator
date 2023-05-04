#pragma once
#include <vector>
#include <string>
#include "Transformator.h"
class ModeSelector
{
public:
	ModeSelector(const std::vector<std::string>& modes);
	std::string selectNewMode(const std::string& currentMode);
protected:
	bool isInModes(const std::string& mode);

	std::vector<std::string> modes;
private:
	virtual void printModes() = 0;
	virtual std::string readMode() = 0;
	std::string updateMode(const std::string& currentMode);
};