#pragma once
#include <fstream>
#include "Bitmap.h"
class PixelsLoader
{
public:
	static void createAndLoadPixels(Bitmap& bitmap);
private:
	static void loadPixels(std::ifstream& bitmapFile, Bitmap& bitmap);
	static void loadPixel(std::ifstream& bitmapFile, Pixel& bitmap);
	static void loadFromFile(Bitmap& bitmap);
};

