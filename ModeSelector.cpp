#include <iostream>
#include <algorithm>
#include "ModeSelector.h"
using namespace std;

ModeSelector::ModeSelector(const vector<string>& modes)
{
	this->modes = modes;
}

string ModeSelector::selectNewMode(const string& currentMode)
{
	printModes();
	return updateMode(currentMode);
}

string ModeSelector::updateMode(const string& currentMode)
{
	string readedMode = readMode();
	if (readedMode == "Undo")
		readedMode = currentMode;
	return readedMode;
}

bool ModeSelector::isInModes(const string& mode)
{
	return find(modes.begin(), modes.end(), mode) == modes.end();
}
