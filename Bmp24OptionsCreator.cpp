#include "Bmp24OptionsCreator.h"
#include "Bmp24Loader.h"
#include "Bmp24Saver.h"
#include "Bmp24.h"
#include "Bmp24HeadersOperator.h"
#include "Bmp24Transformator.h"
#include "LoadSourceOption.h"
#include "SaveImageOption.h"
#include "TransformImageOption.h"

using namespace std;

Bmp24OptionsCreator::Bmp24OptionsCreator(const Config& appConfig, std::shared_ptr<Communicator> communicator, std::shared_ptr<OneArgNotifier<std::vector<Mask>>> filterChangedNotifier,
	std::shared_ptr<OneArgNotifier<std::string>> formatChangedNotifier, std::shared_ptr<OneArgNotifier<std::string>> outputNameChangedNotifier,
	std::shared_ptr<OneArgNotifier<std::string>> sourceNameChangedNotifier) : appConfig(appConfig), communicator(communicator)
{
	this->filterChangedNotifier = filterChangedNotifier;
	this->formatChangedNotifier = formatChangedNotifier;
	this->outputNameChangedNotifier = outputNameChangedNotifier;
	this->sourceNameChangedNotifier = sourceNameChangedNotifier;
}

map<string, shared_ptr<Option>> Bmp24OptionsCreator::createBmp24SpecifiedMenuOptions()
{
	bmp24SourceChangedNotifier = shared_ptr<OneArgNotifier<Bmp24>>(new OneArgNotifier<Bmp24>());
	bmp24DestinationChangedNotifier = shared_ptr<OneArgNotifier<Bmp24>>(new OneArgNotifier<Bmp24>());
	createTransformOption();
	createLoadOption();
	createSaveOption();
    return bmp24SpecifiedOptions;
}

void Bmp24OptionsCreator::createTransformOption()
{
	string optionName = "Transform";
	auto transformImageOption = shared_ptr<TransformImageOption<Bmp24Transformator, Bmp24>>
		(new TransformImageOption<Bmp24Transformator, Bmp24>(optionName, communicator, appConfig["transformators"]["bmp24_transformator"]));
	auto namedOption = pair<string, shared_ptr<Option>>(optionName, transformImageOption);
	transformImageOption->connectNotifiers(filterChangedNotifier, formatChangedNotifier, outputNameChangedNotifier, bmp24SourceChangedNotifier, bmp24DestinationChangedNotifier);
	bmp24SpecifiedOptions.insert(namedOption);
}

void Bmp24OptionsCreator::createLoadOption()
{
	string optionName = "Load";
	auto loadSourceOption = shared_ptr<LoadSourceOption<Bmp24, Bmp24HeadersOperator, Bmp24Loader>>
		(new LoadSourceOption<Bmp24, Bmp24HeadersOperator, Bmp24Loader>(optionName, communicator, appConfig["source_images_path"]));
	auto namedOption = pair<string, shared_ptr<Option>>(optionName, loadSourceOption);
	loadSourceOption->connectNotifiers(formatChangedNotifier, sourceNameChangedNotifier, bmp24SourceChangedNotifier);
	bmp24SpecifiedOptions.insert(namedOption);
}

void Bmp24OptionsCreator::createSaveOption()
{
	string optionName = "Save";
	auto saveImageOption = shared_ptr<SaveImageOption<Bmp24, Bmp24Saver>>
		(new SaveImageOption<Bmp24, Bmp24Saver>(optionName, communicator, appConfig["destination_images_path"]));
	auto namedOption = pair<string, shared_ptr<Option>>(optionName, saveImageOption);
	saveImageOption->connectNotifiers(bmp24DestinationChangedNotifier);
	bmp24SpecifiedOptions.insert(namedOption);
}
