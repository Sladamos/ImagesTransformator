#pragma once
#include "ImagesSaver.h"
#include "Bmp24.h"
class Bmp24Saver : public ImagesSaver
{
private:
	void save(std::ofstream& bitmapFile, Image* image) override;
	void writeFileHeader(std::ofstream& bitmapFile, const Bmp24Header& fileHeader);
	void writeInfoHeader(std::ofstream& bitmapFile, const Bmp24InfoHeader& infoHeader);
	void writePixels(std::ofstream& bitmapFile, Bmp24* bitmap);
	void writePixel(std::ofstream& bitmapFile, const Pixel& pixel);
};

