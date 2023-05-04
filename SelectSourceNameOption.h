#pragma once
#include "Option.h"
#include "OneArgEvent.h"
class SelectSourceNameOption : public Option
{
public:
	SelectSourceNameOption(const std::string& name, std::shared_ptr<Communicator> communicator);
	virtual void execute() override;
	virtual std::string getDescription() override;
	void onFormatChanged(std::shared_ptr<std::string> newFormat = nullptr);
	void onSourceNameChanged(std::shared_ptr<std::string> newSourceName);

	const OneArgEvent<std::string> sourceNameChanged;
private:
	std::shared_ptr<std::string> sourceName;
};

