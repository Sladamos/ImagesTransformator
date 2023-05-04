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
	void onFormatChanged(std::shared_ptr<std::string> newFormat);
	virtual void printOptions() = 0;

	const Event exitProgram;
protected:
	std::vector<std::shared_ptr<Option>> indexedOptions;
	std::map<std::string, std::shared_ptr<Option>> namedOptions;
private:
	void addBmp24Options(const std::string& format);
	void addNamedOptionsAsIndexed();
	void addExitOption();
	void addChangeFormatOption();
	void addSelectOutputNameOption();
	void addOptionForAllFormats(std::shared_ptr<Option> option);

	std::string currentFormat;
	std::shared_ptr<Option> selectMatchingOption(const std::string& handledInput);
	std::shared_ptr<Option> selectNamedOption(const std::string& handledInput);
	std::shared_ptr<Communicator> communicator;
	std::map<std::string, std::map<std::string, std::shared_ptr<Option>>> options;
	std::vector<std::string> formats;
};

