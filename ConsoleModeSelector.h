#pragma once
#include <iostream>
#include "ModeSelector.h"
class ConsoleModeSelector : public ModeSelector
{
public:
	ConsoleModeSelector(const std::vector<std::string>& modes);
private:
	virtual void printModes() override;
	virtual std::string readMode() override;
};

