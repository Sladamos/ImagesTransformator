#pragma once
#include "BitmapsLoader.h"
class Bitmaps24BitLoader : public BitmapsLoader
{
public:
	void loadBmp(const std::string& bitmapName) override;
private:
	BitmapFileHeader loadBmpFileHeader(std::ifstream& bitmapFile) override;
	BitmapInfoHeader loadBmpInfoHeader(std::ifstream& bitmapFile) override;
};

