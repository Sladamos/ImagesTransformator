#pragma once
#include <iostream>
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
	LoadSourceOption(const std::string& name) : Option(name)
	{
		this->creator = std::shared_ptr<T>(new T());
		this->headersOperator = std::shared_ptr<H>(new H());
		this->contentLoader = std::shared_ptr<L>(new L());
	}

	virtual void execute() override
	{
		std::string sourceName;
		std::cin >> sourceName;
		auto image = creator->createImage(sourceName);
		headersOperator->loadHeaders(image);
		
		if (headersOperator->areHeadersValidate(image))
		{
			contentLoader->loadImageContent(image.get());
			//invoke sourceChange event
			std::cout << image->toString();
		}
		//return image->toString();
		
	}

	virtual std::string getDescription() override
	{
		return "Load source";
	}
private:
	bool isLoaded;
	std::shared_ptr<T> creator;
	std::shared_ptr<H> headersOperator;
	std::shared_ptr<L> contentLoader;
};

