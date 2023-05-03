#pragma once
#include "Communicator.h"
class ConsoleCommunicator : public Communicator
{
	ConsoleCommunicator();
	virtual std::string handleInput() override;
};

