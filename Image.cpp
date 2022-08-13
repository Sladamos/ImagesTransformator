#include "Image.h"

std::string Image::getName() const
{
	return name;
}

void Image::setName(const std::string& name)
{
	this->name = name;
}

std::ostream& operator<<(std::ostream& os, const Image& image)
{
	os << image.name;
	return os;
}