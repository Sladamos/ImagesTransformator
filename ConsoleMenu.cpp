#include "ConsoleMenu.h"
#include "ConsoleCommunicator.h"

using namespace std;

ConsoleMenu::ConsoleMenu() : Menu(shared_ptr<Communicator>(new ConsoleCommunicator()))
{

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
