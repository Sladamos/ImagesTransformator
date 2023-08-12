#pragma once
#include <vector>
#include <string>
#include <algorithm>

class StringsOperator
{
public:
    std::vector<std::string> split(const std::string& str, char c = ' ');
    bool isNumber(const std::string& str);
    std::string toLowerCase(const std::string& str);
    std::string toUpperCase(const std::string& str);
    std::string decorateString(const std::string& str);
};

