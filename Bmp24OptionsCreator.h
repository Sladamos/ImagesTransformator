#pragma once
#include <map>
#include <vector>
#include <string>
#include <memory>
#include "Option.h"
#include "OneArgNotifier.h"
#include "Bmp24.h"
#include "Mask.h"
#include "Config.h"
class Bmp24OptionsCreator
{
public:
	Bmp24OptionsCreator(const Config& appConfig, std::shared_ptr<Communicator> communicator, std::shared_ptr<OneArgNotifier<std::vector<Mask>>> filterChangedNotifier,
		std::shared_ptr<OneArgNotifier<std::string>> formatChangedNotifier, std::shared_ptr<OneArgNotifier<std::string>> outputNameChangedNotifier,
		std::shared_ptr<OneArgNotifier<std::string>> sourceNameChangedNotifier);
	std::map<std::string, std::shared_ptr<Option>> createBmp24SpecifiedMenuOptions();
private:
	void createTransformOption();
	void createLoadOption();
	void createSaveOption();

	Config appConfig;
	std::shared_ptr<Communicator> communicator;
	std::shared_ptr<OneArgNotifier<std::vector<Mask>>> filterChangedNotifier;
	std::shared_ptr<OneArgNotifier<std::string>> formatChangedNotifier;
	std::shared_ptr<OneArgNotifier<std::string>> outputNameChangedNotifier;
	std::shared_ptr<OneArgNotifier<std::string>> sourceNameChangedNotifier;
	std::shared_ptr<OneArgNotifier<Bmp24>> bmp24SourceChangedNotifier;
	std::shared_ptr<OneArgNotifier<Bmp24>> bmp24DestinationChangedNotifier;
	std::map<std::string, std::shared_ptr<Option>> bmp24SpecifiedOptions;
};

