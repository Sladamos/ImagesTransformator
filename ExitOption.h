#pragma once
#include "Option.h"
#include "Event.h"
class ExitOption : public Option
{
public:
	ExitOption(const std::string& name, std::shared_ptr<Communicator> communicator = nullptr);
	const Event exitProgram;
	virtual std::string getDescription() override;
	virtual void execute() override;
};

