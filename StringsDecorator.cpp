#include "StringsDecorator.h"
#include <sstream>
#include <iomanip>

using namespace std;

string StringsDecorator::squareBracketDecorateString(const string& str, int expectedWidth)
{
    stringstream ss;
    ss << "[" << left << setw(expectedWidth) << str << "]";
    return ss.str();
}
