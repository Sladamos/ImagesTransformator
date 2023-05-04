#include "Menu.h"
#include "MenuOptionsCreator.h"

using namespace std;

Menu::Menu(std::shared_ptr<Communicator> communicator) : communicator(communicator)
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

void Menu::onFormatChanged(std::shared_ptr<std::string> newFormat)
{
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

	return nullptr;
}
