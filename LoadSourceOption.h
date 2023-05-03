#pragma once
#include <stdexcept>
#include "OneArgEvent.h"
#include "Option.h"
#include "Image.h"
#include "HeadersOperator.h"
#include "ImageHeader.h"
#include "ImageContent.h"
#include "ImagesCreator.h"
#include "ImagesLoader.h"

template <class T, class H, class L>
class LoadSourceOption : public Option
{
public:
	LoadSourceOption(const std::string& name, std::shared_ptr<Communicator> communicator) : Option(name, communicator)
	{
		this->creator = std::shared_ptr<ImagesCreator<T>>(new ImagesCreator<T>());
		this->headersOperator = std::shared_ptr<H>(new H());
		this->contentLoader = std::shared_ptr<L>(new L());
		this->image = nullptr;
	}

	virtual void execute() override
	{
		displayText("Give the image name with extension.");
		std::string sourceName = handleInput();

		auto image = creator->createImage(sourceName);
		headersOperator->loadHeaders(image);
		
		if (headersOperator->areHeadersValidate(image))
		{
			contentLoader->loadImageContent(image);
			displayText(image->toString());
			this->image = image;
		}
		else
		{
			displayError("Incorrect source name.");
		}
		
	}

	virtual std::string getDescription() override
	{
		return "Load source image";
	}

	std::shared_ptr<T> getImage()
	{
		if (image == nullptr)
			throw std::domain_error("Firstly load source.");

		return image;
	}
	
	void onFormatChanged(std::string newFormat)
	{
		image == nullptr;
	}
private:
	bool isLoaded;
	std::shared_ptr<T> image;
	std::shared_ptr<ImagesCreator<T>> creator;
	std::shared_ptr<H> headersOperator;
	std::shared_ptr<L> contentLoader;
};

