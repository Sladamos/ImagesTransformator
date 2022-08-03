#pragma once
#include <fstream>
#include "Bitmap.h"
class PixelsLoader
{
public:
	static void createAndLoadPixels(Bitmap& bitmap);
private:
	static void loadPixels(std::ifstream& bitmapFile, Bitmap& bitmap);
	static void loadFromFile(Bitmap& bitmap);
	static Pixel** createUninitializedPixels(int width, int height);
};

