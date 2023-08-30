#pragma once
#include <vector>
#include <string>
#include "OneArgNotifier.h"
#include "Option.h"
class ChangeFormatOption : public Option
{
public:
	ChangeFormatOption(const std::string& name, std::shared_ptr<Communicator> communicator, const std::vector<std::string>& formats);
	void connectNotifiers(std::shared_ptr<OneArgNotifier<std::string>> formatChangedNotifier);
	virtual void execute() override;
	virtual std::string getDescription() override;
private:
	std::shared_ptr<std::string> getSelectedFormat();
	bool isFormatSupported(const std::string& format);
	void onFormatChanged(std::shared_ptr<std::string> format);

	std::vector<std::string> formats;
	std::shared_ptr<std::string> currentFormat;
	std::shared_ptr<OneArgNotifier<std::string>> formatChangedNotifier;
};

