#include "Menu.h"
#include "StringsOperator.h"

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
	StringsOperator strOp;
	//TODO trycatch
	if (strOp.isNumber(handledInput))
	{
		int index = stoi(handledInput) - 1;
		return options[index];
	}
	else
	{
		for (auto option : options)
		{
			if (handledInput == option->getName())
				return option;
		}
	}

	return options[options.size() - 1];
}
