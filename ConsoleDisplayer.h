#pragma once
#include "Displayer.h"
class ConsoleDisplayer : public Displayer
{
	virtual void displayText(const std::string& text) override;
};

