#pragma once
#include <iostream>
#include "Menu.h"
class ConsoleMenu : public Menu
{
public:
	virtual void handleInput() override;
	virtual void printOptions() override;
private:
	void clearConsole();
};

