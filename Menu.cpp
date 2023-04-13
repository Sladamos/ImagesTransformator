#include "Menu.h"
#include "ExitOption.h"
#include "LoadSourceOption.h"
#include "Bmp24Creator.h"
#include "Bmp24Loader.h"
#include "Bmp24HeadersOperator.h"

using namespace std;

Menu::Menu()
{
	std::string optionName = "Exit";
	shared_ptr<ExitOption> exitOption = shared_ptr<ExitOption>(new ExitOption(optionName));
	auto exit = [this]() {exitProgram.invoke(); };
	exitOption->exitProgram += exit;
	
	pair<string, shared_ptr<Option>> namedOption = pair<string, shared_ptr<Option>>(optionName, exitOption);
	namedOptions.insert(namedOption);
	optionName = "LoadSource";
	namedOption = pair<string, shared_ptr<Option>>(optionName, new LoadSourceOption<Bmp24Creator, Bmp24HeadersOperator, Bmp24Loader>(optionName));
	namedOptions.insert(namedOption);

	addNamedOptionsAsIndexed();
}

void Menu::addNamedOptionsAsIndexed()
{
	for (auto it = namedOptions.begin(); it != namedOptions.end(); it++)
		indexedOptions.push_back(it->second);
}

void Menu::selectAndExecuteOption()
{
	string input = handleInput();
	shared_ptr<Option> selectedOption = selectMatchingOption(input);
	selectedOption->execute();
}

shared_ptr<Option> Menu::selectMatchingOption(const string& handledInput)
{
	try
	{
		int index = stoi(handledInput) - 1;
		return indexedOptions[index];
	}
	catch (exception& err)
	{
		return selectNamedOption(handledInput);
	}

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
