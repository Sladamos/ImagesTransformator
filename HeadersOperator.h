#pragma once
#include <string>
#include <fstream>
#include "Bitmap.h"
class HeadersOperator
{
public:
	void loadHeaders(Bitmap* bitmap);
	virtual bool areHeadersValidate(Bitmap* bitmap) = 0;
protected:
	BitmapFileHeader loadBmpFileHeader(std::ifstream& bitmapFile);
	BitmapInfoHeader loadBmpInfoHeader(std::ifstream& bitmapFile);
private:
	virtual void load(std::ifstream& bitmapFile, Bitmap* bitmap) = 0;
};

