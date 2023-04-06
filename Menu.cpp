#include "Menu.h"

using namespace std;

Menu::Menu()
{/*
	options = std::shared_ptr<std::map<int, std::string>>(new map<int, string>());
	vector<pair<int, string>> optionsVec = {
	pair<int, string>(1, "Source name")};

	for(auto p)
	options->insert()*/
	//TODO: option class
}

void Menu::selectAndExecuteOption()
{
	string input = handleInput();
	shared_ptr<Option> selectedOption = selectMatchingOption(input);
	selectedOption->execute();
}

shared_ptr<Option> Menu::selectMatchingOption(const string& handledInput)
{
	for (auto option : options)
	{
		if (handledInput == option->getName())
			return option;
	}
	//TODO input may be an index
	return options[options.size() - 1];
}
