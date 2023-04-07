#pragma once
#include <string>
#include <sstream>
#include <iomanip>
class Option
{
public:
	Option(const std::string& name);

	std::string toString();
	virtual void execute() = 0;
protected:
	virtual std::string getDescription() = 0;
private:
	std::string name;
};

