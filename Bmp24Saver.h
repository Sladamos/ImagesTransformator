#pragma once
#include "ImagesSaver.h"
#include "Bmp24.h"
class Bmp24Saver : public ImagesSaver
{
private:
	void writeImageHeader(std::ofstream& imageFile, const ImageHeader& imageHeader) override;
	void writeImageContent(std::ofstream& imageFile, const ImageContent& imageContent) override;
	void writePixels(std::ofstream& bitmapFile, Bmp24* bitmap);
	void writePixel(std::ofstream& bitmapFile, const Pixel& pixel);
};

