#pragma once
#include <iostream>
#include <string>
#include "ImageHeader.h"
#include "ImageContent.h"
class Image
{
public:
	Image(Image* source, const std::string& imageName);
	Image();
	virtual ~Image() = default;
	std::string getName() const;
	const ImageHeader& getImageHeader() const;
	ImageContent& getImageContent() const;
	void setName(const std::string& name);
	void setImageHeader(ImageHeaderPtr imageHeader);
	virtual std::string toString();
private:
	ImageHeaderPtr imageHeader;
	ImageContentPtr imageContent;
	std::string name;
};

