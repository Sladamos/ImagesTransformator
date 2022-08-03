#pragma once
#include <string>
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
class Bitmap
{
public:
	std::string getName() const;
	BitmapFileHeader getFileHeader();
	BitmapInfoHeader getInfoHeader();
	void setName(const std::string& name);
	void setFileHeader(const BitmapFileHeader& fileHeader);
	void setInfoHeader(const BitmapInfoHeader& infoHeader);
	void resetHeaders();
private:
	std::string name;
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;
};

