#pragma once
#include "Option.h"
#include "OneArgEvent.h"
#include "OneArgNotifier.h"
class SelectOutputNameOption : public Option
{
public:
	SelectOutputNameOption(const std::string& name, std::shared_ptr<Communicator> communicator);
	void connectNotifiers(std::shared_ptr<OneArgNotifier<std::string>> formatChangedNotifier);
	virtual void execute() override;
	virtual std::string getDescription() override;
	void onFormatChanged(std::shared_ptr<std::string> newFormat = nullptr);
	void onOutputNameChanged(std::shared_ptr<std::string> newOutputName);

	const OneArgEvent<std::string> outputNameChanged;
private:
	std::shared_ptr<std::string> outputName;
};

