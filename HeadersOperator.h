#pragma once
#include <string>
#include <fstream>
#include "Bmp24.h"
class HeadersOperator
{
public:
	void loadHeaders(Image* image);
	virtual bool areHeadersValidate(Image* image) = 0;
protected:
	Bmp24Header loadBmpFileHeader(std::ifstream& bitmapFile);
	Bmp24InfoHeader loadBmpInfoHeader(std::ifstream& bitmapFile);
private:
	virtual void load(std::ifstream& imageFile, Image* image) = 0;
};

