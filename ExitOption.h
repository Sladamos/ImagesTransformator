#pragma once
#include "Option.h"
#include "Event.h"
class ExitOption : public Option
{
public:
	const Event exitProgram;
	virtual std::string getDescription() override;
	virtual void execute() override;
};

