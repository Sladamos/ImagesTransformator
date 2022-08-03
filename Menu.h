#pragma once
#include "Bitmap.h"
class Menu
{
public:
	void startProgram();
private:
	void printMenu();
	void handleOption();
	void clearConsole();
	std::string readNameFromInput();

	int option;
	bool isProgramLaunched{ 1 };
	Bitmap source, output;
};

