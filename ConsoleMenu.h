#pragma once
#include <iostream>
#include <sstream>
#include "Menu.h"
#include "Communicator.h"
class ConsoleMenu : public Menu
{
public:
	ConsoleMenu();
	virtual void printOptions() override;
private:
	void clearConsole();
};

