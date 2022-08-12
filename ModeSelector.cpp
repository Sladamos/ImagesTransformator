#include <iostream>
#include "ModeSelector.h"
using namespace std;

string ModeSelector::selectNewMode(const string& currentMode)
{
	printSelector();
	return updateMode(currentMode);
}

void ModeSelector::printSelector()
{
	cout
		<< "1." << " Sobel " << "\n"
		<< "Press any other number to undo\n\n";
}

string ModeSelector::updateMode(const string& currentMode)
{
	int option;
	string newMode;
	cin >> option;

	switch (option)
	{
	case 1:
		newMode = "Sobel";
		break;
	default:
		newMode = currentMode;
	}
	return newMode;
}

