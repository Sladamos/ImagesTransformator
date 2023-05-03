#pragma once
#include <iostream>
#include <string>
#include "ImageHeader.h"
#include "ImageContent.h"
template<class H, class C>
class Image
{
public:
	Image(const std::string& imageName)
	{
		imageHeader = std::shared_ptr<H>(new H());
		imageContent = std::shared_ptr<C>(new C());
		name = imageName;
	}

	Image() : Image("EMPTY IMAGE")
	{
	}

	std::string getName() const
	{
		return name;
	}

	std::shared_ptr<H> getImageHeader() const
	{
		return imageHeader;
	}

	std::shared_ptr<C> getImageContent() const
	{
		return imageContent;
	}

	virtual void setName(const std::string& name)
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

