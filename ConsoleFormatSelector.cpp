#include "ConsoleFormatSelector.h"
using namespace std;

ConsoleFormatSelector::ConsoleFormatSelector(const std::vector<std::string>& imagesFormats) : FormatSelector(imagesFormats)
{
}

void ConsoleFormatSelector::printFormats()
{
	cout << "Choose correct format\n";
	for (auto name : imagesFormats)
		cout << name << "\n";
	cout << "Undo\n\n";
}

std::string ConsoleFormatSelector::readFormat()
{
	string format;
	do
	{
		cin >> format;
	} while (format != "Undo" && find(imagesFormats.begin(), imagesFormats.end(), format) == imagesFormats.end());

	return format;
}
