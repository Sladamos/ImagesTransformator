#pragma once
#include <memory>
#include "Menu.h"
class ProgramEngine
{
public:
	ProgramEngine(std::shared_ptr<Menu> menu, std::shared_ptr<Notifier> programExitedNotifier);
	void startProgram();
	void turnOffProgram();
private:
	bool isProgramLaunched;
	std::shared_ptr<Menu> menu;
};

