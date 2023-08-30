#include "Menu.h"
#include "MenuOptionsCreator.h"
#include "StringsOperator.h"
#include "OneArgNotifier.h"

using namespace std;

Menu::Menu(shared_ptr<Communicator> communicator, const Config& appConfig, std::shared_ptr<Notifier> programExitedNotifier) : communicator(communicator)
{
	auto formatChangedNotifier = shared_ptr<OneArgNotifier<string>>(new OneArgNotifier<string>());
	formatChangedNotifier->notified += [this](auto format) { this->onFormatChanged(format); };
	auto optionsCreator = MenuOptionsCreator(communicator, appConfig, programExitedNotifier, formatChangedNotifier);
	options = optionsCreator.createOptions();
	auto formats = optionsCreator.getFormats();
	auto changeFormatOption = options[formats[0]]["Format"];
	changeFormatOption->execute();
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
	if (selectedOption != nullptr)
	{
		selectedOption->execute();
	}
}

shared_ptr<Option> Menu::selectMatchingOption(const string& handledInput)
{
	try
	{
		int index = stoi(handledInput) - 1;
		if (index < indexedOptions.size() && index >= 0)
		{
			return indexedOptions[index];
		}
	}
	catch (exception& err)
	{
	}
	return selectNamedOption(handledInput);
}

void Menu::onFormatChanged(shared_ptr<string> newFormat)
{
	namedOptions = options[*newFormat];
	addNamedOptionsAsIndexed();
}

shared_ptr<Option> Menu::selectNamedOption(const string& handledInput)
{
	StringsOperator stringsOperator;
	string handledName = stringsOperator.toLowerCase(handledInput);
	for (auto option : namedOptions)
	{
		string optionName = stringsOperator.toLowerCase(option.first);
		if (handledName == optionName)
			return option.second;
	}

	return nullptr;
}
