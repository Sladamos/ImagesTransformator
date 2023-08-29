#pragma once
#include <map>
#include <vector>
#include <memory>
#include <string>
#include "Option.h"
#include "Event.h"
#include "Config.h"
class Menu
{
public:
	Menu(std::shared_ptr<Communicator> communicator, const Config& appConfig);
	void selectAndExecuteOption();
	void onFormatChanged(std::shared_ptr<std::string> newFormat);
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
	std::map<std::string, std::map<std::string, std::shared_ptr<Option>>> options;
};

