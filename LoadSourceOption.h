#pragma once
#include <stdexcept>
#include "Option.h"
#include "Image.h"
#include "HeadersOperator.h"
#include "ImageHeader.h"
#include "ImageContent.h"
#include "ImagesCreator.h"
#include "ImagesLoader.h"
#include "OneArgNotifier.h"

template <class T, class H, class L>
class LoadSourceOption : public Option
{
public:
	LoadSourceOption(const std::string& name, std::shared_ptr<Communicator> communicator, const std::string& source_images_path) : Option(name, communicator)
	{
		this->creator = std::shared_ptr<ImagesCreator<T>>(new ImagesCreator<T>());
		this->headersOperator = std::shared_ptr<H>(new H(source_images_path));
		this->contentLoader = std::shared_ptr<L>(new L(source_images_path));
		this->image = nullptr;
		this->sourceName = nullptr;
	}

	void connectNotifiers(std::shared_ptr<OneArgNotifier<std::string>> formatChangedNotifier, std::shared_ptr<OneArgNotifier<std::string>> sourceNameChangedNotifier,
		std::shared_ptr<OneArgNotifier<T>> sourceChangedNotifier)
	{
		formatChangedNotifier->notified += [this](auto format) {this->onFormatChanged(); };
		sourceNameChangedNotifier->notified += [this](auto sourceName) {this->onSourceNameChanged(sourceName); };
		sourceChangedNotifier->notified += [this](auto image) {this->onSourceChanged(image); };
		this->sourceChangedNotifier = sourceChangedNotifier;
	}

	virtual void execute() override
	{
		if (sourceName == nullptr)
		{
			displayError("Specify input name before load.");
			return;
		}

		auto image = creator->createImage();
		image->setName(*sourceName);
		headersOperator->loadHeaders(image);
		
		if (headersOperator->areHeadersValidate(image))
		{
			contentLoader->loadImageContent(image);
			displayText(image->toString());
			sourceChangedNotifier->notifyListeners(image);
		}
		else
		{
			displayError("Incorrect source name.");
		}
		
	}

	virtual std::string getDescription() override
	{
		if (image == nullptr)
		{
			return "Load source image";
		}
		else
		{
			return "Loaded source image: " + image->getName();
		}
	}
private:
	void onFormatChanged(std::shared_ptr<std::string> newFormat = nullptr)
	{
		sourceChangedNotifier->notifyListeners(nullptr);
	}

	void onSourceChanged(std::shared_ptr<T> source)
	{
		image = source;
	}

	void onSourceNameChanged(std::shared_ptr<std::string> sourceName)
	{
		this->sourceName = sourceName;
		sourceChangedNotifier->notifyListeners(nullptr);
	}

	bool isLoaded;
	std::shared_ptr<std::string> sourceName;
	std::shared_ptr<T> image;
	std::shared_ptr<ImagesCreator<T>> creator;
	std::shared_ptr<H> headersOperator;
	std::shared_ptr<L> contentLoader;
	std::shared_ptr<OneArgNotifier<T>> sourceChangedNotifier;
};

