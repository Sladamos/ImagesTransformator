#pragma once
#include <vector>
#include <string>
#include "OneArgEvent.h"
#include "Option.h"
class ChangeFormatOption : public Option
{
public:
	ChangeFormatOption(const std::string& name, std::shared_ptr<Communicator> communicator, const std::vector<std::string>& formats);
	virtual void execute() override;
	virtual std::string getDescription() override;

	const OneArgEvent<std::string> formatChanged;
private:
	std::string getSupportedFormats();
	bool isFormatSupported(const std::string& format);

	std::vector<std::string> formats;
};

