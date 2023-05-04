#include <sstream>
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
