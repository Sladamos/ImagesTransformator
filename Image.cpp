#include "Image.h"

Image::Image(Image* source, const std::string& imageName) : name(imageName)
{
	imageHeader = source->imageHeader;
	imageContent = source->imageContent;
}

std::string Image::getName() const
{
	return name;
}

const ImageHeader& Image::getImageHeader() const
{
	return *imageHeader;
}

const ImageContent& Image::getImageContent() const
{
	return *imageContent;
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

std::string Image::toString()
{
	return imageHeader->toString();
}
