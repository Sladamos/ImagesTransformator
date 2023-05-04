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
	std::string getName();
	virtual void execute() = 0;
protected:
	virtual std::string getDescription() = 0;
	void displayText(const std::string& text);
	void displayError(const std::string& text);
	std::string handleInput();
private:
	std::string name;
	std::shared_ptr<Communicator> communicator;
};

