#pragma once
#include "ImagesSaver.h"
#include "Bitmap.h"
class Bmp24Saver : public ImagesSaver
{
private:
	void save(std::ofstream& bitmapFile, Bitmap* bitmap) override;
	void writeFileHeader(std::ofstream& bitmapFile, const BitmapFileHeader& fileHeader);
	void writeInfoHeader(std::ofstream& bitmapFile, const BitmapInfoHeader& infoHeader);
	void writePixels(std::ofstream& bitmapFile, Bitmap* bitmap);
	void writePixel(std::ofstream& bitmapFile, const Pixel& pixel);
};

