#include "Image.h"

template<class H, class C>
Image<H, C>::Image(Image* source, const std::string& imageName) : name(imageName)
{
	imageHeader = source->imageHeader;
	imageContent = source->imageContent;
}

template<class H, class C>
Image<H,C>::Image() : name("EMPTY IMAGE")
{
	imageHeader = nullptr;
	imageContent = nullptr;
}

template<class H, class C>
std::string Image<H,C>::getName() const
{
	return name;
}

template<class H, class C>
const H& Image<H,C>::getImageHeader() const
{
	return *imageHeader;
}

template<class H, class C>
C& Image<H,C>::getImageContent() const
{
	return *imageContent;
}

template<class H, class C>
void Image<H,C>::setImageHeader(std::shared_ptr<H> imageHeader)
{
	this->imageHeader = imageHeader;
}

template<class H, class C>
void Image<H,C>::setName(const std::string& name)
{
	this->name = name;
}

template<class H, class C>
std::string Image<H,C>::toString()
{
	return imageHeader->toString();
}
