#pragma once
#include <string>
#include <fstream>
#include "Bitmap.h"
class HeadersOperator
{
public:
	void loadHeaders(Bitmap& bitmap);
	bool areHeadersValidate(const Bitmap& bitmap);
private:
	BitmapFileHeader loadBmpFileHeader(std::ifstream& bitmapFile);
	BitmapInfoHeader loadBmpInfoHeader(std::ifstream& bitmapFile);
};

