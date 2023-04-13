#pragma once
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

	}

	virtual void execute() override
	{
		auto image = creator->createImage();
		//TODO change from raw to smart pointers
		//headersOperator->loadHeaders(image.get());
		
		//if (headersOperator->areHeadersValidate(image.get()))
			contentLoader->loadImageContent(image.get());
		//return image->toString();
		
	}

	virtual std::string getDescription() override
	{
		return "Load source";
	}
private:
	bool isLoaded;
	std::shared_ptr<H> headersOperator;
	std::shared_ptr<T> creator;
	std::shared_ptr<L> contentLoader;
};

