#include "Image.h"

std::string Image::getName() const
{
	return name;
}

void Image::clear()
{
}

void Image::setName(const std::string& name)
{
	this->name = name;
}
