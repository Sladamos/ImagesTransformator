#pragma once
#include <string>
#include <fstream>
#include "Bitmap.h"
class HeadersLoader
{
public:
	static void loadHeaders(Bitmap& bitmap);
private:
	static BitmapFileHeader loadBmpFileHeader(std::ifstream& bitmapFile);
	static BitmapInfoHeader loadBmpInfoHeader(std::ifstream& bitmapFile);
};

