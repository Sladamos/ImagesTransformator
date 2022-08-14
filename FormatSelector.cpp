#include <iostream>
#include <algorithm>
#include "FormatSelector.h"
using namespace std;

string FormatSelector::selectNewFormat(const vector<string>& imagesFormats)
{
	printSelector(imagesFormats);
	return readFormatFromInput(imagesFormats);
}

void FormatSelector::printSelector(const vector<string>& imagesFormats)
{
	cout << "Choose correct format\n";
	for (auto name : imagesFormats)
		cout << name << "\n";
	cout << "Undo\n\n";
}

string FormatSelector::readFormatFromInput(const vector<string>& imagesFormats)
{
	string format;
	do
	{
		cin >> format;
	} while (format != "Undo" && find(imagesFormats.begin(), imagesFormats.end(), format) == imagesFormats.end());

	return format;
}