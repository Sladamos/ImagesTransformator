#include "Menu.h"
#include "ExitOption.h"
#include "LoadSourceOption.h"
#include "Bmp24Loader.h"
#include "Bmp24HeadersOperator.h"

using namespace std;

Menu::Menu(std::shared_ptr<Communicator> communicator)
{
	this->communicator = communicator;
	addBmp24Options();
	addExitOption();
	onFormatChanged("Bmp24");
}

void Menu::addBmp24Options()
{
	string format = "Bmp24";
	string optionName = "LoadSource";
	auto loadSourceOption = shared_ptr<LoadSourceOption<Bmp24, Bmp24HeadersOperator, Bmp24Loader>>
		(new LoadSourceOption<Bmp24, Bmp24HeadersOperator, Bmp24Loader>(optionName, communicator));

	auto namedOptions = map<string, shared_ptr<Option>>();
	auto namedOption = pair<string, shared_ptr<Option>>(optionName, loadSourceOption);

	//selectFormatOption->selectFormat += [loadSourceOption]() {loadSourceOption->onFormatChanged(); };
	//add this on format changed
	//remember that format need function with string arg!
	namedOptions.insert(namedOption);
	options.insert({format, namedOptions});
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

std::shared_ptr<Option> Menu::selectNamedOption(const std::string& handledInput)
{
	for (auto option : namedOptions)
	{
		if (handledInput == option.first)
			return option.second;
	}

	return namedOptions["Exit"];
}

void Menu::onFormatChanged(std::string newFormat)
{
	currentFormat = newFormat;
	namedOptions = options[newFormat];
	addNamedOptionsAsIndexed();
}
