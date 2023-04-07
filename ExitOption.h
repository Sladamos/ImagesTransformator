#pragma once
#include "Option.h"
#include "Event.h"
class ExitOption : public Option
{
public:
	ExitOption(const std::string& name);
	const Event exitProgram;
	virtual std::string getDescription() override;
	virtual void execute() override;
};

