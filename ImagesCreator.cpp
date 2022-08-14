#include "ImagesCreator.h"
#include "Bmp24.h"

void ImagesCreator::updateImage(Image*& image, const std::string& imageFormat)
{
	if (image != nullptr)
		delete image;

	if (imageFormat == "Bmp24")
		image = new Bmp24();
}