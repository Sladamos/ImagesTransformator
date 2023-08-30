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

MenuOptionsCreator::MenuOptionsCreator(std::shared_ptr<Communicator> communicator, const Config& appConfig) : appConfig(appConfig), communicator(communicator)
{
	filterChangedNotifier = shared_ptr<OneArgNotifier<vector<Mask>>>(new OneArgNotifier<vector<Mask>>());
	formatChangedNotifier = shared_ptr<OneArgNotifier<string>>(new OneArgNotifier<string>());
	outputNameChangedNotifier = shared_ptr<OneArgNotifier<string>>(new OneArgNotifier<string>());
	sourceNameChangedNotifier = shared_ptr<OneArgNotifier<string>>(new OneArgNotifier<string>());
	bmp24ChangedNotifier = shared_ptr<OneArgNotifier<Bmp24>>(new OneArgNotifier<Bmp24>());
}

map<string, map<string, shared_ptr<Option>>> MenuOptionsCreator::createOptions(Menu* menu)
{
	formats = vector<string>{ "Bmp24", "JPG" };
	for (auto format : formats)
	{
		options.insert({ format, map<string, shared_ptr<Option>>() });
	}
	addExitOption(menu);
	addChangeFilterOption();
	addChangeFormatOption(menu);
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
	auto changeFormatOption = std::dynamic_pointer_cast<ChangeFormatOption>(options[format]["Format"]);
	auto changeFilterOption = std::dynamic_pointer_cast<ChangeFilterOption>(options[format]["Filter"]);
	auto selectOutputNameOption = std::dynamic_pointer_cast<SelectOutputNameOption>(options[format]["Output"]);
	auto selectSourceNameOption = std::dynamic_pointer_cast<SelectSourceNameOption>(options[format]["Source"]);

	string optionName = "Load";
	auto loadSourceOption = shared_ptr<LoadSourceOption<Bmp24, Bmp24HeadersOperator, Bmp24Loader>>
		(new LoadSourceOption<Bmp24, Bmp24HeadersOperator, Bmp24Loader>(optionName, communicator, appConfig["source_images_path"]));
	auto namedOption = pair<string, shared_ptr<Option>>(optionName, loadSourceOption);
	loadSourceOption->connectNotifiers(formatChangedNotifier, sourceNameChangedNotifier, bmp24ChangedNotifier);
	namedOptions.insert(namedOption);

	optionName = "Transform";
	auto transformImageOption = shared_ptr<TransformImageOption<Bmp24Transformator, Bmp24>>
		(new TransformImageOption<Bmp24Transformator, Bmp24>(optionName, communicator, appConfig["transformators"]["bmp24_transformator"]));
	namedOption = pair<string, shared_ptr<Option>>(optionName, transformImageOption);
	changeFormatOption->formatChanged += [transformImageOption](auto format) {transformImageOption->onFormatChanged(); };
	selectOutputNameOption->outputNameChanged += [transformImageOption](auto name) {transformImageOption->onOutputNameChanged(name); };
	loadSourceOption->sourceChanged += [transformImageOption](auto source) { transformImageOption->onSourceChanged(source); };
	transformImageOption->connectNotifiers(filterChangedNotifier);
	namedOptions.insert(namedOption);

	optionName = "Save";
	auto saveImageOption = shared_ptr<SaveImageOption<Bmp24, Bmp24Saver>>
		(new SaveImageOption<Bmp24, Bmp24Saver>(optionName, communicator, appConfig["destination_images_path"]));
	namedOption = pair<string, shared_ptr<Option>>(optionName, saveImageOption);
	transformImageOption->destinationChanged += [saveImageOption](auto destination) {saveImageOption->onDestinationChanged(destination); };
	namedOptions.insert(namedOption);
}


void MenuOptionsCreator::addOptionForAllFormats(std::shared_ptr<Option> option)
{
	for (auto& kv : options)
	{
		kv.second.insert({ option->getName(), option });
	}
}

void MenuOptionsCreator::addExitOption(Menu* menu)
{
	string optionName = "Exit";
	shared_ptr<ExitOption> exitOption = shared_ptr<ExitOption>(new ExitOption(optionName));
	exitOption->exitProgram += [menu]() {menu->exitProgram.invoke(); };
	addOptionForAllFormats(exitOption);
}

void MenuOptionsCreator::addChangeFormatOption(Menu* menu)
{
	string optionName = "Format";
	shared_ptr<ChangeFormatOption> changeFormatOption = shared_ptr<ChangeFormatOption>(new ChangeFormatOption(optionName, communicator, formats));
	changeFormatOption->connectNotifiers(formatChangedNotifier);
	addOptionForAllFormats(changeFormatOption);
	//TODO TODO TODO TODO
	//changeFormatOption->formatChanged += [menu](auto format) {menu->onFormatChanged(format); };
}

void MenuOptionsCreator::addSelectOutputNameOption()
{
	string optionName = "Output";
	auto selectOutputNameOption = shared_ptr<SelectOutputNameOption>(new SelectOutputNameOption(optionName, communicator));
	selectOutputNameOption->connectNotifiers(formatChangedNotifier);
	addOptionForAllFormats(selectOutputNameOption);
}

void MenuOptionsCreator::addSelectSourceNameOption()
{
	string optionName = "Source";
	auto selectSourceNameOption = shared_ptr<SelectSourceNameOption>(new SelectSourceNameOption(optionName, communicator));
	selectSourceNameOption->connectNotifiers(formatChangedNotifier);
	addOptionForAllFormats(selectSourceNameOption);
}

void MenuOptionsCreator::addChangeFilterOption()
{
	string optionName = "Filter";
	shared_ptr<ChangeFilterOption> changeFilterOption = shared_ptr<ChangeFilterOption>(new ChangeFilterOption(optionName, communicator, appConfig["masks_path"]));
	changeFilterOption->connectNotifiers(filterChangedNotifier);
	addOptionForAllFormats(changeFilterOption);
}
