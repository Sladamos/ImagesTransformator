#pragma once
#include <string>
#include <fstream>
#include "Bitmap.h"
class HeadersOperator
{
public:
	void loadHeaders(Bitmap& bitmap);
	virtual bool areHeadersValidate(const Bitmap& bitmap) = 0;
protected:
	BitmapFileHeader loadBmpFileHeader(std::ifstream& bitmapFile);
	BitmapInfoHeader loadBmpInfoHeader(std::ifstream& bitmapFile);
};

