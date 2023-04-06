#include "ConsoleMenu.h"
using namespace std;

void ConsoleMenu::handleOption()
{
}

void ConsoleMenu::print()
{
	clearConsole();
	//forEach possible option
	//display
	cout << endl
		//<< "1." << " Source name: " << source->getName() << "\n"
		<< "2." << " Load source" << "\n"
		//<< "3." << " Output name: " << outputName << "\n"
		//<< "4." << " Current format: " << imageFormat << "\n"
		//<< "5." << " Current mode: " << currentMode << "\n"
		<< "6." << " Transform image" << "\n"
		<< "9. Exit\n\n";
	//mapa numer opcji | nazwa opcji
}

void ConsoleMenu::clearConsole()
{
	system("cls");
}
