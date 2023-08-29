#pragma once
#include "Option.h"
template <class I, class S>
class SaveImageOption : public Option
{
public:
	SaveImageOption(const std::string& optionName, std::shared_ptr<Communicator> communicator, const std::string& directory_path) : Option(optionName, communicator)
	{
		imagesSaver = std::shared_ptr<S>(new S(directory_path));
		destination = nullptr;
	}

	virtual void execute() override
	{
		if (destination != nullptr)
		{
			imagesSaver->saveImage(destination);
			displayText("Image saved properly.");
		}
		else
		{
			displayError("Transform image before saving.");
		}
	}

	virtual std::string getDescription() override
	{
		return "Save transformated image";
	}

	void onDestinationChanged(std::shared_ptr<I> destination)
	{
		this->destination = destination;
	}
private:
	std::shared_ptr<S> imagesSaver;
	std::shared_ptr<I> destination;
};

