#pragma once
#include <string>
class Option
{
public:
	virtual std::string getDescription() = 0;
	virtual void execute() = 0;
};

