#pragma once
#include <iostream>
#include "Menu.h"
class ConsoleMenu : public Menu
{
public:
	virtual void handleOption() override;
	virtual void print() override;
private:
	void clearConsole();
};

