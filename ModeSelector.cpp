#include <iostream>
#include <algorithm>
#include "ModeSelector.h"
using namespace std;

string ModeSelector::selectNewMode(const string& currentMode, const vector<string>& modes)
{
	printSelector(modes);
	return updateMode(currentMode, modes);
}

void ModeSelector::printSelector(const vector<string>& transformators)
{
	cout << "Choose correct mode\n";
	for (auto name : transformators)
		cout << name << "\n";
	cout << "Undo\n\n";
}

string ModeSelector::updateMode(const string& currentMode, const vector<string>& transformators)
{
	string readedMode = readModeFromInput(transformators);
	if (readedMode == "Undo")
		readedMode = currentMode;
	return readedMode;
}

string ModeSelector::readModeFromInput(const vector<string>& transformators)
{
	string newMode;
	do
	{
		cin >> newMode;
	}
	while (newMode != "Undo" && find(transformators.begin(), transformators.end(), newMode) == transformators.end());
	
	return newMode;
}
