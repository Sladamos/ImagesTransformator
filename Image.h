#pragma once
#include <iostream>
#include <string>
#include "ImageHeader.h"
class Image
{
public:
	virtual ~Image() = default;
	Image(Image* source, const std::string& imageName);
	std::string getName() const;
	ImageHeaderPtr getImageHeader() const;
	void setName(const std::string& name);
	void setImageHeader(ImageHeaderPtr imageHeader);
	std::string toString();
private:
	ImageHeaderPtr imageHeader;
	std::string name;
};

