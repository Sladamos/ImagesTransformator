#pragma once
#include <iostream>
#include <string>
#include "ImageHeader.h"
#include "ImageContent.h"
template<class H, class C>
class Image
{
public:
	Image(Image* source, const std::string& imageName) : name(imageName)
	{
		imageHeader = source->imageHeader;
		imageContent = source->imageContent;
	}

	Image() : name("EMPTY IMAGE")
	{
		imageHeader = nullptr;
		imageContent = nullptr;

	}

	std::string getName() const
	{
		return name;
	}

	const H& getImageHeader() const
	{
		return *imageHeader;
	}

	C& getImageContent() const
	{
		return *imageContent;
	}

	void setName(const std::string& name)
	{
		this->name = name;
	}

	void setImageHeader(std::shared_ptr<H> imageHeader)
	{
		this->imageHeader = imageHeader;
	}

	virtual std::string toString()
	{
		return imageHeader->toString();
	}
private:
	std::shared_ptr<H> imageHeader;
	std::shared_ptr<C> imageContent;
	std::string name;
};

