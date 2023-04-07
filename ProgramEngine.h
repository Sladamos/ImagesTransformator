#pragma once
#include <memory>
#include "Menu.h"
class ProgramEngine
{
public:
	ProgramEngine(std::shared_ptr<Menu> menu);
	void startProgram();
	void turnOffProgram();
private:
	bool isProgramLaunched;
	std::shared_ptr<Menu> menu;
};

