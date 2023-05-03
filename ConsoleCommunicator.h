#pragma once
#include "Communicator.h"
class ConsoleCommunicator : public Communicator
{
public:
	ConsoleCommunicator();
	virtual std::string handleInput() override;
};

