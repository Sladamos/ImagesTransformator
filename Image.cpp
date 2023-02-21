#include "Image.h"

std::string Image::getName() const
{
	return name;
}

ImageHeaderPtr Image::getImageHeader() const
{
	return imageHeader;
}

void Image::setName(const std::string& name)
{
	this->name = name;
}

void Image::setImageHeader(ImageHeaderPtr imageHeader)
{
	this->imageHeader = imageHeader;
}

void Image::setName(const std::string& name)
{
	this->name = name;
}
