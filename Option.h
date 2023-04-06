#pragma once
#include <string>
class Option
{
public:
	Option(const std::string& name);
	const std::string& getName();
	virtual void execute() = 0;
private:
	std::string name;
};

