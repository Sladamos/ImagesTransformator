#include "MenuOptionsCreator.h"
#include "ChangeFormatOption.h"
#include "SelectOutputNameOption.h"
#include "SelectSourceNameOption.h"
#include "ChangeFilterOption.h"
#include "ExitOption.h"
#include "Bmp24OptionsCreators.h"

using namespace std;

MenuOptionsCreator::MenuOptionsCreator(std::shared_ptr<Communicator> communicator, const Config& appConfig, shared_ptr<Notifier> programExitedNotifier,
	shared_ptr<OneArgNotifier<string>> formatChangedNotifier) : appConfig(appConfig), communicator(communicator)
{
	this->programExitedNotifier = programExitedNotifier;
	this->formatChangedNotifier = formatChangedNotifier;
	filterChangedNotifier = shared_ptr<OneArgNotifier<vector<Mask>>>(new OneArgNotifier<vector<Mask>>());
	outputNameChangedNotifier = shared_ptr<OneArgNotifier<string>>(new OneArgNotifier<string>());
	sourceNameChangedNotifier = shared_ptr<OneArgNotifier<string>>(new OneArgNotifier<string>());
}

map<string, map<string, shared_ptr<Option>>> MenuOptionsCreator::createOptions()
{
	formats = vector<string>{ "Bmp24", "JPG" };
	for (auto format : formats)
	{
		options.insert({ format, map<string, shared_ptr<Option>>() });
	}
	addExitOption();
	addChangeFilterOption();
	addChangeFormatOption();
	addSelectOutputNameOption();
	addSelectSourceNameOption();
	addBmp24Options(formats[0]);
	return options;
}

const std::vector<std::string>& MenuOptionsCreator::getFormats()
{
	return formats;
}

void MenuOptionsCreator::addBmp24Options(const std::string& format)
{
	auto& namedOptions = options[format];
	auto bmp24OptionsCreator = Bmp24OptionsCreators(appConfig, communicator, filterChangedNotifier, formatChangedNotifier, outputNameChangedNotifier, sourceNameChangedNotifier);
	auto bmp24SpecifiedOptions = bmp24OptionsCreator.createBmp24SpecifiedMenuOptions();
	namedOptions.insert(bmp24SpecifiedOptions.begin(), bmp24SpecifiedOptions.end());
}

void MenuOptionsCreator::addOptionForAllFormats(std::shared_ptr<Option> option)
{
	for (auto& kv : options)
	{
		kv.second.insert({ option->getName(), option });
	}
}

void MenuOptionsCreator::addExitOption()
{
	string optionName = "Exit";
	shared_ptr<ExitOption> exitOption = shared_ptr<ExitOption>(new ExitOption(optionName));
	exitOption->connectNotifiers(programExitedNotifier);
	addOptionForAllFormats(exitOption);
}

void MenuOptionsCreator::addChangeFormatOption()
{
	string optionName = "Format";
	shared_ptr<ChangeFormatOption> changeFormatOption = shared_ptr<ChangeFormatOption>(new ChangeFormatOption(optionName, communicator, formats));
	changeFormatOption->connectNotifiers(formatChangedNotifier);
	addOptionForAllFormats(changeFormatOption);
}

void MenuOptionsCreator::addSelectOutputNameOption()
{
	string optionName = "Output";
	auto selectOutputNameOption = shared_ptr<SelectOutputNameOption>(new SelectOutputNameOption(optionName, communicator));
	selectOutputNameOption->connectNotifiers(formatChangedNotifier, outputNameChangedNotifier);
	addOptionForAllFormats(selectOutputNameOption);
}

void MenuOptionsCreator::addSelectSourceNameOption()
{
	string optionName = "Source";
	auto selectSourceNameOption = shared_ptr<SelectSourceNameOption>(new SelectSourceNameOption(optionName, communicator));
	selectSourceNameOption->connectNotifiers(formatChangedNotifier, sourceNameChangedNotifier);
	addOptionForAllFormats(selectSourceNameOption);
}

void MenuOptionsCreator::addChangeFilterOption()
{
	string optionName = "Filter";
	shared_ptr<ChangeFilterOption> changeFilterOption = shared_ptr<ChangeFilterOption>(new ChangeFilterOption(optionName, communicator, appConfig["masks_path"]));
	changeFilterOption->connectNotifiers(filterChangedNotifier);
	addOptionForAllFormats(changeFilterOption);
}
