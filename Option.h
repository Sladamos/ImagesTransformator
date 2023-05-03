#pragma once
#include <string>
#include <sstream>
#include <iomanip>
#include <memory>
#include "Communicator.h"
class Option
{
public:
	Option(const std::string& name, std::shared_ptr<Communicator> communicator);
	std::string toString();
	virtual void execute() = 0;
	void displayText(const std::string& text);
	std::string handleInput();
protected:
	virtual std::string getDescription() = 0;
private:
	std::string name;
	std::shared_ptr<Communicator> communicator;
};

