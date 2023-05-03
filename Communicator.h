#pragma once
#include <memory>
#include "Displayer.h"
class Communicator
{
public:
	Communicator(std::shared_ptr<Displayer> displayer);
	void displayText(const std::string& text);
	virtual std::string handleInput() = 0;
private:
	std::shared_ptr<Displayer> displayer;
};

