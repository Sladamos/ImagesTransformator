#include "Splitter.h"
#include <sstream>
using namespace std;

vector<string> Splitter::split(const string& str, char c)
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
