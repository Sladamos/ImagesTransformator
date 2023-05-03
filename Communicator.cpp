#include "Communicator.h"

Communicator::Communicator(std::shared_ptr<Displayer> displayer)
{
	this->displayer = displayer;
}

void Communicator::displayText(const std::string& text)
{
	displayer->displayText(text);
}
