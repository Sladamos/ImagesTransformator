#pragma once
#include <string>
#include <fstream>
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
class BitmapsLoader
{
public:
	virtual void loadBmp(const std::string& bitmapName) = 0;
private:
	virtual BitmapFileHeader loadBmpFileHeader(std::ifstream& bitmapFile) = 0;
	virtual BitmapInfoHeader loadBmpInfoHeader(std::ifstream& bitmapFile) = 0;
};

