#pragma once
#include <string>
#include "Bitmap.h"
class ImagesCreator
{
public:
	static void updateImage(Bitmap*& image, const std::string& imageFormat);
};

