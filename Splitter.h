#pragma once
#include <vector>
#include <string>

class Splitter
{
public:
    std::vector<std::string> split(const std::string& str, char c = ' ');
};

