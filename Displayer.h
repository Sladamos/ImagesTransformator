#pragma once
#include <string>
class Displayer
{
public:
	virtual void displayText(const std::string& text) = 0;
	virtual void displayError(const std::string& text) = 0;
};
