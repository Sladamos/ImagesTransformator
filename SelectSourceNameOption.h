#pragma once
#include "Option.h"
#include "OneArgNotifier.h"
class SelectSourceNameOption : public Option
{
public:
	SelectSourceNameOption(const std::string& name, std::shared_ptr<Communicator> communicator);
	void connectNotifiers(std::shared_ptr<OneArgNotifier<std::string>> formatChangedNotifier, std::shared_ptr<OneArgNotifier<std::string>> sourceNameChangedNotifier);
	virtual void execute() override;
	virtual std::string getDescription() override;
private:
	void onFormatChanged(std::shared_ptr<std::string> newFormat = nullptr);
	void onSourceNameChanged(std::shared_ptr<std::string> newSourceName);

	std::shared_ptr<std::string> sourceName;
	std::shared_ptr<OneArgNotifier<std::string>> sourceNameChangedNotifier;
};

