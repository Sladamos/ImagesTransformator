#include "ConsoleMenu.h"
#include "ConsoleCommunicator.h"

using namespace std;

ConsoleMenu::ConsoleMenu(const Config& appConfig, std::shared_ptr<Notifier> programExitedNotifier) : Menu(shared_ptr<Communicator>(new ConsoleCommunicator()), appConfig, programExitedNotifier)
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