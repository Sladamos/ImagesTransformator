#pragma once
#include <map>
#include <vector>
#include <memory>
#include <string>
#include "Option.h"
#include "Event.h"
class Menu
{
public:
	Menu(std::shared_ptr<Communicator> communicator);
	void selectAndExecuteOption();
	virtual void printOptions() = 0;

	const Event exitProgram;
protected:
	std::vector<std::shared_ptr<Option>> indexedOptions;
	std::map<std::string, std::shared_ptr<Option>> namedOptions;
private:
	void addNamedOptionsAsIndexed();
	std::shared_ptr<Option> selectMatchingOption(const std::string& handledInput);
	std::shared_ptr<Option> selectNamedOption(const std::string& handledInput);
	std::shared_ptr<Communicator> communicator;
};

