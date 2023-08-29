#pragma once
#include "Menu.h"
#include "Config.h"
#include "OptionsCreator.h"
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
	Config appConfig;
};

