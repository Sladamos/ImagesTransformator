#pragma once
#include <vector>
#include <map>
#include <string>
#include "Mask.h"
#include "Menu.h"
#include "Config.h"
#include "OptionsCreator.h"
#include "OneArgNotifier.h"
#include "Bmp24.h"
class MenuOptionsCreator : public OptionsCreator<Menu>
{
public:
	MenuOptionsCreator(std::shared_ptr<Communicator> communicator, const Config& appConfig);
	virtual std::map<std::string, std::map<std::string, std::shared_ptr<Option>>> createOptions(Menu* menu) override;
	const std::vector<std::string>& getFormats();
private:
	void addBmp24Options(const std::string& format);
	void addExitOption(Menu* menu);
	void addChangeFormatOption(Menu* menu);
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
	std::shared_ptr<OneArgNotifier<Bmp24>> bmp24ChangedNotifier;
	Config appConfig;
};

