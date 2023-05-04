#include <algorithm>
#include "FormatSelector.h"
using namespace std;

FormatSelector::FormatSelector(const std::vector<std::string>& imagesFormats) : imagesFormats(imagesFormats)
{
}

string FormatSelector::selectNewFormat()
{
	printFormats();
	return readFormat();
}
