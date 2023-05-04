#pragma once
#include "Displayer.h"
class ConsoleDisplayer : public Displayer
{
public:
	virtual void displayText(const std::string& text) override;
	virtual void displayError(const std::string& text) override;
};

