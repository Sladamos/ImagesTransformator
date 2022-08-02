#pragma once
#include <string>
class Menu
{
public:
	void startProgram();
private:
	void printMenu();
	void handleOption();
	void clearConsole();

	int option;
	bool isProgramLaunched{ 1 };
	std::string sourceName, outputName;
};

