#pragma once
#include "Option.h"
#include "OneArgNotifier.h"
class SelectOutputNameOption : public Option
{
public:
	SelectOutputNameOption(const std::string& name, std::shared_ptr<Communicator> communicator);
	void connectNotifiers(std::shared_ptr<OneArgNotifier<std::string>> formatChangedNotifier, std::shared_ptr<OneArgNotifier<std::string>> outputNameChangedNotifier);
	virtual void execute() override;
	virtual std::string getDescription() override;
private:
	void onFormatChanged(std::shared_ptr<std::string> newFormat = nullptr);
	void onOutputNameChanged(std::shared_ptr<std::string> newOutputName);

	std::shared_ptr<std::string> outputName;
	std::shared_ptr<OneArgNotifier<std::string>> outputNameChangedNotifier;
};

