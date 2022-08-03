#pragma once
#include <string>
#include <fstream>
#include "Bitmap.h"
class HeadersOperator
{
public:
	static void loadHeaders(Bitmap& bitmap);
	static bool areHeadersValidate(const Bitmap& bitmap);
private:
	static BitmapFileHeader loadBmpFileHeader(std::ifstream& bitmapFile);
	static BitmapInfoHeader loadBmpInfoHeader(std::ifstream& bitmapFile);
};

