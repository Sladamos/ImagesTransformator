#pragma once
#include <map>
#include <vector>
#include <memory>
#include <string>
class Menu
{
public:
	Menu();
	void selectAndExecuteOption();
	virtual void printOptions() = 0;
protected:
	std::shared_ptr<std::map<int, std::string>> options;
	virtual void handleInput() = 0;
private:
	void selectMatchingOption();
	void executeOption();
};

