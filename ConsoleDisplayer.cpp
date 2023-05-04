#include <iostream>
#include "ConsoleDisplayer.h"

void ConsoleDisplayer::displayText(const std::string& text)
{
	std::cout << text << std::endl;
}

void ConsoleDisplayer::displayError(const std::string& text)
{
	displayText(text);
}
