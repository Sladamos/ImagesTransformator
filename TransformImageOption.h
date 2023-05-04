#pragma once
#include "Option.h"
#include "Transformator.h"
template <class T, class I>
class TransformImageOption : public Option
{
public:
	TransformImageOption(const std::string& optionName, std::shared_ptr<Communicator> communicator):
		Option(optionName, communicator)
	{
		this->transformator = nullptr;
	}

	virtual void execute() override
	{
		if (outputName == nullptr)
		{
			displayText("Specify output name.");
		}
		else if (source == nullptr)
		{
			displayText("Load source first.");
		}
		else if (transformator == nullptr)
		{
			displayText("Select filter first.");
		}
		else
		{
			auto destination = transformator->transformateImage(source);
			destination->setName(*outputName);
			destinationChanged.invoke(destination);
		}
		destinationChanged.invoke(nullptr);
	}

	virtual std::string getDescription() override
	{
		return "Transform image when source is loaded and output name is selected.";
	}

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
		destinationChanged.invoke(nullptr);
	}

	void onFilterChanged(std::shared_ptr<std::vector<Mask>> masks)
	{
		transformator = std::shared_ptr<T>(new T(*masks));
	}

	const OneArgEvent<I> destinationChanged;
private:
	std::shared_ptr<std::string> outputName;
	std::shared_ptr<I> source;
	std::shared_ptr<T> transformator;
};
