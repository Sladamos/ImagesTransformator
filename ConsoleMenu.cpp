#include "ConsoleMenu.h"
using namespace std;

std::string ConsoleMenu::handleInput()
{
	std::string output;
	cin >> output;
	clearConsole();
	return output;
}

void ConsoleMenu::printOptions()
{
	stringstream ss;
	ss << endl;
	int numberOfOptions = indexedOptions.size();

	for (int i = 0; i < numberOfOptions; i++)
	{
		ss << i + 1 << ". " << indexedOptions[i]->toString() << endl;
	}
	cout << ss.str();
}

void ConsoleMenu::clearConsole()
{
	system("cls");
}
