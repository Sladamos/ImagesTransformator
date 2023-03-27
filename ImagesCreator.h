#pragma once
#include <string>
#include "Image.h"
template<class T>
class ImagesCreator
{
public:
	virtual std::shared_ptr<T> createImage() = 0;
};

