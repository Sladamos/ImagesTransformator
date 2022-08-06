#pragma once
#include <fstream>
#include "Bitmap.h"
class BitmapsSaver
{
public:
	void saveBitmap(const Bitmap& bitmap);
private:
	void writeFileHeader(std::ofstream& bitmapFile, const BitmapFileHeader& fileHeader);
	void writeInfoHeader(std::ofstream& bitmapFile, const BitmapInfoHeader& infoHeader);
	void writePixels(std::ofstream& bitmapFile, const Bitmap& bitmap);
	void writePixel(std::ofstream& bitmapFile, const Pixel& pixel);
};

