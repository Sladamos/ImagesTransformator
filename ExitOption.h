#pragma once
#include "Option.h"
#include "Notifier.h"
class ExitOption : public Option
{
public:
	ExitOption(const std::string& name, std::shared_ptr<Communicator> communicator = nullptr);
	void connectNotifiers(std::shared_ptr<Notifier> programExitedNotifier);
	virtual std::string getDescription() override;
	virtual void execute() override;
private:
	std::shared_ptr<Notifier> programExitedNotifier;
};

