#pragma once
#include <string>
#include "Image.h"
class ImagesCreator
{
public:
	static void updateImage(Image*& image, const std::string& imageFormat);
};

