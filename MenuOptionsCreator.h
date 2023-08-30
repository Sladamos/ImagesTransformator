#pragma once
#include <vector>
#include <map>
#include <string>
#include "Mask.h"
#include "Config.h"
#include "OptionsCreator.h"
#include "OneArgNotifier.h"
#include "Bmp24.h"
#include "Notifier.h"

class MenuOptionsCreator : public OptionsCreator
{
public:
	MenuOptionsCreator(std::shared_ptr<Communicator> communicator, const Config& appConfig, std::shared_ptr<Notifier> programExitedNotifier,
		std::shared_ptr<OneArgNotifier<std::string>> formatChangedNotifier);
	virtual std::map<std::string, std::map<std::string, std::shared_ptr<Option>>> createOptions() override;
	const std::vector<std::string>& getFormats();
private:
	void addBmp24Options(const std::string& format);
	void addExitOption();
	void addChangeFormatOption();
	void addSelectOutputNameOption();
	void addSelectSourceNameOption();
	void addChangeFilterOption();
	void addOptionForAllFormats(std::shared_ptr<Option> option);

	std::shared_ptr<Communicator> communicator;
	std::map<std::string, std::map<std::string, std::shared_ptr<Option>>> options;
	std::vector<std::string> formats;
	std::shared_ptr<OneArgNotifier<std::vector<Mask>>> filterChangedNotifier;
	std::shared_ptr<OneArgNotifier<std::string>> formatChangedNotifier;
	std::shared_ptr<OneArgNotifier<std::string>> outputNameChangedNotifier;
	std::shared_ptr<OneArgNotifier<std::string>> sourceNameChangedNotifier;
	std::shared_ptr<Notifier> programExitedNotifier;
	Config appConfig;
};

