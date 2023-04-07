#include "ConsoleMenu.h"
using namespace std;

std::string ConsoleMenu::handleInput()
{
	clearConsole();
	std::string output;
	cin >> output;
	return output;
}

void ConsoleMenu::printOptions()
{
	stringstream ss;
	ss << endl;
	int numberOfOptions = indexedOptions.size();

	for (int i = 0; i < numberOfOptions; i++)
	{
		ss << i + i << ". " << indexedOptions[i]->getDescription();
	}

	cout << ss.str();
}

void ConsoleMenu::clearConsole()
{
	system("cls");
}
