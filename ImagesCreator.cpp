#include "ImagesCreator.h"

void ImagesCreator::updateImage(Bitmap*& image, const std::string& imageFormat)
{
	if (image != nullptr)
		delete image;

	if (imageFormat == "Bmp24")
		image = new Bitmap();
}