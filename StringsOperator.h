#pragma once
#include <vector>
#include <string>
#include <algorithm>

class StringsOperator
{
public:
    std::vector<std::string> split(const std::string& str, char c = ' ');
    bool isNumber(const std::string& str);
};

