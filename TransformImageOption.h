#pragma once
#include "Option.h"
#include "Transformator.h"
#include "OneArgNotifier.h"
template <class T, class I>
class TransformImageOption : public Option
{
public:
	TransformImageOption(const std::string& optionName, std::shared_ptr<Communicator> communicator, Config transformatorConfig):
		Option(optionName, communicator), transformatorConfig(transformatorConfig)
	{
		this->transformator = nullptr;
	}

	void connectNotifiers(std::shared_ptr<OneArgNotifier<std::vector<Mask>>> filterChangedNotifier, std::shared_ptr<OneArgNotifier<std::string>> formatChangedNotifier,
		std::shared_ptr<OneArgNotifier<std::string>> outputNameChangedNotifier, std::shared_ptr<OneArgNotifier<I>> sourceChangedNotifier,
		std::shared_ptr<OneArgNotifier<I>> destinationChangedNotifier)
	{
		filterChangedNotifier->notified += [this](auto filter) { this->onFilterChanged(filter); };
		formatChangedNotifier->notified += [this](auto format) { this->onFormatChanged(format); };
		outputNameChangedNotifier->notified += [this](auto outputName) { this->onOutputNameChanged(outputName); };
		sourceChangedNotifier->notified += [this](auto image) { this->onSourceChanged(image); };
		this->destinationChangedNotifier = destinationChangedNotifier;
	}

	virtual void execute() override
	{
		if (outputName == nullptr)
		{
			displayError("Specify output name.");
		}
		else if (source == nullptr)
		{
			displayError("Load source before transformate it.");
		}
		else if (transformator == nullptr)
		{
			displayError("Select filter before transformation.");
		}
		else
		{
			auto destination = transformator->transformateImage(source);
			destination->setName(*outputName);
			destinationChangedNotifier->notifyListeners(destination);
			displayText("Transformated source properly.");
		}
	}

	virtual std::string getDescription() override
	{
		return "Transform source image";
	}
private:
	void onOutputNameChanged(std::shared_ptr<std::string> outputName)
	{
		this->outputName = outputName;
	}

	void onSourceChanged(std::shared_ptr<I> source)
	{
		this->source = source;
	}

	void onFormatChanged(std::shared_ptr<std::string> newFormat = nullptr)
	{
		destinationChangedNotifier->notifyListeners(nullptr);
	}

	void onFilterChanged(std::shared_ptr<std::vector<Mask>> masks)
	{
		transformator = std::shared_ptr<T>(new T(*masks, transformatorConfig));
	}

	std::shared_ptr<std::string> outputName;
	std::shared_ptr<I> source;
	std::shared_ptr<T> transformator;
	std::shared_ptr<OneArgNotifier<I>> destinationChangedNotifier;
	Config transformatorConfig;
};
