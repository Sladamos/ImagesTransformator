#include <iostream>
#include "ModeSelector.h"
using namespace std;

string ModeSelector::selectNewMode(const string& currentMode, const map<string, Transformator*>& transformators)
{
	printSelector(transformators);
	return updateMode(currentMode, transformators);
}

void ModeSelector::printSelector(const map<string, Transformator*>& transformators)
{
	cout << "Choose correct mode\n";
	for (auto pair : transformators)
		cout << pair.first << "\n";
	cout << "Undo\n\n";
}

string ModeSelector::updateMode(const string& currentMode, const map<string, Transformator*>& transformators)
{
	string readedMode = readModeFromInput(transformators);
	if (readedMode == "Undo")
		readedMode = currentMode;
	return readedMode;
}

string ModeSelector::readModeFromInput(const map<string, Transformator*>& transformators)
{
	string newMode;
	do
	{
		cin >> newMode;
	}
	while (newMode != "Undo" && transformators.find(newMode) == transformators.end());
	return newMode;
}
