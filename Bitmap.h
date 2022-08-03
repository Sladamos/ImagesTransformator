#pragma once
#include <string>
#include "Pixel.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
class Bitmap
{
public:
	~Bitmap();
	std::string getName() const;
	BitmapFileHeader getFileHeader() const;
	BitmapInfoHeader getInfoHeader() const;
	Pixel** getPixels() const;
	int getNumberOfZeroBytes() const;
	void setNumberOfZeroBytes(int numberOfZeroBytes);
	void setPixels(Pixel** pixels);
	void setName(const std::string& name);
	void setFileHeader(const BitmapFileHeader& fileHeader);
	void setInfoHeader(const BitmapInfoHeader& infoHeader);
	void resetHeaders();
private:
	Pixel** pixels{nullptr};
	std::string name;
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;
	int numberOfZeroBytes{0};
};

