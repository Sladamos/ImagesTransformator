#include "MenuOptionsCreator.h"
#include "ChangeFormatOption.h"
#include "SelectOutputNameOption.h"
#include "SelectSourceNameOption.h"
#include "ChangeFilterOption.h"
#include "TransformImageOption.h"
#include "ExitOption.h"
#include "LoadSourceOption.h"
#include "SaveImageOption.h"
#include "Bmp24Loader.h"
#include "Bmp24Saver.h"
#include "Bmp24.h"
#include "Bmp24HeadersOperator.h"
#include "Bmp24Transformator.h"

using namespace std;

MenuOptionsCreator::MenuOptionsCreator(std::shared_ptr<Communicator> communicator, const Config& appConfig, shared_ptr<Notifier> programExitedNotifier,
	shared_ptr<OneArgNotifier<string>> formatChangedNotifier) : appConfig(appConfig), communicator(communicator)
{
	this->programExitedNotifier = programExitedNotifier;
	this->formatChangedNotifier = formatChangedNotifier; //shared_ptr(new OneArgNotifier<string>());
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
	std::shared_ptr<OneArgNotifier<Bmp24>> bmp24SourceChangedNotifier = shared_ptr<OneArgNotifier<Bmp24>>(new OneArgNotifier<Bmp24>());
	std::shared_ptr<OneArgNotifier<Bmp24>> bmp24DestinationChangedNotifier = shared_ptr<OneArgNotifier<Bmp24>>(new OneArgNotifier<Bmp24>());
	auto& namedOptions = options[format];

	string optionName = "Load";
	auto loadSourceOption = shared_ptr<LoadSourceOption<Bmp24, Bmp24HeadersOperator, Bmp24Loader>>
		(new LoadSourceOption<Bmp24, Bmp24HeadersOperator, Bmp24Loader>(optionName, communicator, appConfig["source_images_path"]));
	auto namedOption = pair<string, shared_ptr<Option>>(optionName, loadSourceOption);
	loadSourceOption->connectNotifiers(formatChangedNotifier, sourceNameChangedNotifier, bmp24SourceChangedNotifier);
	namedOptions.insert(namedOption);

	optionName = "Transform";
	auto transformImageOption = shared_ptr<TransformImageOption<Bmp24Transformator, Bmp24>>
		(new TransformImageOption<Bmp24Transformator, Bmp24>(optionName, communicator, appConfig["transformators"]["bmp24_transformator"]));
	namedOption = pair<string, shared_ptr<Option>>(optionName, transformImageOption);
	transformImageOption->connectNotifiers(filterChangedNotifier, formatChangedNotifier, outputNameChangedNotifier, bmp24SourceChangedNotifier, bmp24DestinationChangedNotifier);
	namedOptions.insert(namedOption);

	optionName = "Save";
	auto saveImageOption = shared_ptr<SaveImageOption<Bmp24, Bmp24Saver>>
		(new SaveImageOption<Bmp24, Bmp24Saver>(optionName, communicator, appConfig["destination_images_path"]));
	namedOption = pair<string, shared_ptr<Option>>(optionName, saveImageOption);
	saveImageOption->connectNotifiers(bmp24DestinationChangedNotifier);
	namedOptions.insert(namedOption);
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
