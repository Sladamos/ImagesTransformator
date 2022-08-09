#pragma once
#include <string>
#include <fstream>
#include "Bitmap.h"
class HeadersOperator
{
public:
	virtual void loadHeaders(Bitmap& bitmap) = 0;
	virtual bool areHeadersValidate(const Bitmap& bitmap) = 0;
protected:
	BitmapFileHeader loadBmpFileHeader(std::ifstream& bitmapFile);
	BitmapInfoHeader loadBmpInfoHeader(std::ifstream& bitmapFile);
};

