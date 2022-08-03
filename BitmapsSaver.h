#pragma once
#include <fstream>
#include "Bitmap.h"
class BitmapsSaver
{
public:
	static void saveBitmap(const Bitmap& bitmap);
private:
	static void writeFileHeader(std::ofstream& bitmapFile, const BitmapFileHeader& fileHeader);
	static void writeInfoHeader(std::ofstream& bitmapFile, const BitmapInfoHeader& infoHeader);
	static void writePixels(std::ofstream& bitmapFile, const Bitmap& bitmap);
	static void writePixel(std::ofstream& bitmapFile, const Pixel& pixel);
};

