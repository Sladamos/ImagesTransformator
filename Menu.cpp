#include "Menu.h"
#include "ExitOption.h"
#include "LoadSourceOption.h"
#include "Bmp24Loader.h"
#include "Bmp24HeadersOperator.h"
#include "ChangeFormatOption.h"
#include "SelectOutputNameOption.h"

using namespace std;

Menu::Menu(std::shared_ptr<Communicator> communicator) : communicator(communicator)
{
	formats = vector<string>{ "Bmp24", "JPG" };
	for (auto format : formats)
	{
		options.insert({ format, map<string, shared_ptr<Option>>() });
	}
	addExitOption();
	addChangeFormatOption();
	addSelectOutputNameOption();
	addBmp24Options(formats[0]);
	auto changeFormatOption = options[formats[0]]["ChangeFormat"];
	changeFormatOption->execute();
}

void Menu::addBmp24Options(const std::string& format)
{
	string optionName = "LoadSource";
	auto loadSourceOption = shared_ptr<LoadSourceOption<Bmp24, Bmp24HeadersOperator, Bmp24Loader>>
		(new LoadSourceOption<Bmp24, Bmp24HeadersOperator, Bmp24Loader>(optionName, communicator));

	auto& namedOptions = options[format];
	auto namedOption = pair<string, shared_ptr<Option>>(optionName, loadSourceOption);

	auto changeFormatOption = std::dynamic_pointer_cast<ChangeFormatOption>(options[formats[0]]["ChangeFormat"]);
	
	changeFormatOption->formatChanged += [loadSourceOption](auto format) {loadSourceOption->onFormatChanged(); };
	namedOptions.insert(namedOption);
}

void Menu::addNamedOptionsAsIndexed()
{
	indexedOptions.clear();
	for (auto it = namedOptions.begin(); it != namedOptions.end(); it++)
		indexedOptions.push_back(it->second);
}

void Menu::selectAndExecuteOption()
{
	string input = communicator->handleInput();
	shared_ptr<Option> selectedOption = selectMatchingOption(input);
	selectedOption->execute();
}

shared_ptr<Option> Menu::selectMatchingOption(const string& handledInput)
{
	try
	{
		int index = stoi(handledInput) - 1;
		if (index < indexedOptions.size())
			return indexedOptions[index];
		else
			throw exception();
	}
	catch (exception& err)
	{
		return selectNamedOption(handledInput);
	}
}

void Menu::addOptionForAllFormats(std::shared_ptr<Option> option)
{
	for (auto& kv : options) 
	{
		kv.second.insert({ option->getName(), option });
	}
}

void Menu::addExitOption()
{
	string optionName = "Exit";
	shared_ptr<ExitOption> exitOption = shared_ptr<ExitOption>(new ExitOption(optionName));
	exitOption->exitProgram += [this]() {exitProgram.invoke();};
	addOptionForAllFormats(exitOption);
}

void Menu::addChangeFormatOption()
{
	string optionName = "ChangeFormat";
	shared_ptr<ChangeFormatOption> changeFormatOption = shared_ptr<ChangeFormatOption>(new ChangeFormatOption(optionName, communicator, formats));
	addOptionForAllFormats(changeFormatOption);
	changeFormatOption->formatChanged += [this](auto format) {this->onFormatChanged(format); };
	changeFormatOption->formatChanged += [changeFormatOption](auto format) {changeFormatOption->onFormatChanged(format); };
}

void Menu::addSelectOutputNameOption()
{
	string optionName = "SelectOutputName";
	auto selectOutputNameOption = shared_ptr<SelectOutputNameOption>(new SelectOutputNameOption(optionName, communicator));
	addOptionForAllFormats(selectOutputNameOption);
	auto changeFormatOption = std::dynamic_pointer_cast<ChangeFormatOption>(options[formats[0]]["ChangeFormat"]);
	changeFormatOption->formatChanged += [selectOutputNameOption](auto format) {selectOutputNameOption->onFormatChanged(); };
}

void Menu::onFormatChanged(std::shared_ptr<std::string> newFormat)
{
	currentFormat = *newFormat;
	namedOptions = options[*newFormat];
	addNamedOptionsAsIndexed();
}

std::shared_ptr<Option> Menu::selectNamedOption(const std::string& handledInput)
{
	for (auto option : namedOptions)
	{
		if (handledInput == option.first)
			return option.second;
	}

	return namedOptions["Exit"];
}
