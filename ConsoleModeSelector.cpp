#include "ConsoleModeSelector.h"
using namespace std;

ConsoleModeSelector::ConsoleModeSelector(const std::vector<std::string>& modes) : ModeSelector(modes)
{
}

void ConsoleModeSelector::printModes()
{
	cout << "Choose correct mode\n";
	for (auto name : modes)
		cout << name << "\n";
	cout << "Undo\n\n";
}

string ConsoleModeSelector::readMode()
{
	string newMode;
	do
	{
		cin >> newMode;
	} while (newMode != "Undo" && isInModes(newMode));

	return newMode;
}
