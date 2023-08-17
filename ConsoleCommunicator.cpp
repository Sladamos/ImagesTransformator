#include <iostream>
#include "ConsoleCommunicator.h"
#include "ConsoleDisplayer.h"

ConsoleCommunicator::ConsoleCommunicator() : Communicator(std::shared_ptr<Displayer>(new ConsoleDisplayer()))
{
}

std::string ConsoleCommunicator::handleInput()
{
	std::string text;
	std::getline(std::cin, text);
	clearConsole();
	return text;
}

void ConsoleCommunicator::clearConsole()
{
	system("cls||clear");
}
