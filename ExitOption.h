#pragma once
#include "Option.h"
class ExitOption : public Option
{
public:
	ExitOption(const std::string& name, std::shared_ptr<Communicator> communicator = nullptr);
	virtual std::string getDescription() override;
	virtual void execute() override;
};

