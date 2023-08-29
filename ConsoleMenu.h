#pragma once
#include <iostream>
#include <sstream>
#include "Menu.h"
#include "Communicator.h"
#include "Config.h"
class ConsoleMenu : public Menu
{
public:
	ConsoleMenu(const Config& appConfig);
	virtual void printOptions() override;
};

