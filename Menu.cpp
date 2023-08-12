#include "Menu.h"
#include "MenuOptionsCreator.h"
#include "StringsOperator.h"

using namespace std;

Menu::Menu(shared_ptr<Communicator> communicator) : communicator(communicator)
{
	auto optionsCreator = MenuOptionsCreator(communicator);
	options = optionsCreator.createOptions(this);
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
		if (index < indexedOptions.size() && index > 0)
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
