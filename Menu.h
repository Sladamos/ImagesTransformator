#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Option.h"
class Menu
{
public:
	Menu();
	void selectAndExecuteOption();
	virtual void printOptions() = 0;
protected:
	std::vector<std::shared_ptr<Option>> options;
	virtual std::string handleInput() = 0;
private:
	std::shared_ptr<Option> selectMatchingOption(const std::string& handledInput);
};

