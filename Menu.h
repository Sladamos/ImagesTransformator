#pragma once
#include <map>
#include <vector>
#include <memory>
#include <string>
#include "Option.h"
#include "Config.h"
#include "Notifier.h"
class Menu
{
public:
	Menu(std::shared_ptr<Communicator> communicator, const Config& appConfig, std::shared_ptr<Notifier> programExitedNotifier);
	void selectAndExecuteOption();
	virtual void printOptions() = 0;
protected:
	std::vector<std::shared_ptr<Option>> indexedOptions;
	std::map<std::string, std::shared_ptr<Option>> namedOptions;
private:
	void onFormatChanged(std::shared_ptr<std::string> newFormat);
	void addNamedOptionsAsIndexed();

	std::shared_ptr<Option> selectMatchingOption(const std::string& handledInput);
	std::shared_ptr<Option> selectNamedOption(const std::string& handledInput);
	std::shared_ptr<Communicator> communicator;
	std::map<std::string, std::map<std::string, std::shared_ptr<Option>>> options;
};

