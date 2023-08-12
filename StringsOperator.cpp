#include <sstream>
#include <iomanip>
#include "StringsOperator.h"
using namespace std;

vector<string> StringsOperator::split(const string& str, char c)
{
    vector<string> result;
    stringstream ss(str);
    string temp;
    while (getline(ss, temp, c)) 
    {
        result.push_back(temp);
    }
    return result;
}

bool StringsOperator::isNumber(const std::string& str)
{
    return !str.empty() && all_of(str.begin(), str.end(), isdigit);
}

std::string StringsOperator::toLowerCase(const std::string& str)
{
    std::string newStr{str};
    std::transform(newStr.begin(), newStr.end(), newStr.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return newStr;
}

std::string StringsOperator::toUpperCase(const std::string& str)
{
    std::string newStr{str};
    std::transform(newStr.begin(), newStr.end(), newStr.begin(),
        [](unsigned char c) { return std::toupper(c); });
    return newStr;
}

std::string StringsOperator::decorateString(const std::string& str)
{
    stringstream ss;
    ss << "[" << left << setw(9) << str << "]";
    return ss.str();
}
