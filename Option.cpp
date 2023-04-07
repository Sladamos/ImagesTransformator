#include "Option.h"
using namespace std;

Option::Option(const std::string& name) : name(name)
{
}

std::string Option::toString()
{
    stringstream ss;
    ss << "[" << name << setw(10) << "]" << ": " << getDescription();
    return ss.str();
}
