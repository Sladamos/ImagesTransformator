#pragma once
#include <string>
#include "Pixel.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
class Bitmap
{
public:
	~Bitmap();
	void sobelTransformationFrom(const Bitmap& source);
	int getNumberOfZeroBytes() const;
	std::string getName() const;
	BitmapFileHeader getFileHeader() const;
	BitmapInfoHeader getInfoHeader() const;
	Pixel** getPixels() const;
	void setNumberOfZeroBytes(int numberOfZeroBytes);
	void setName(const std::string& name);
	void setFileHeader(const BitmapFileHeader& fileHeader);
	void setInfoHeader(const BitmapInfoHeader& infoHeader);
	void createUninitializedPixels();
	void resetHeaders();
private:
	void transformatePixels(const Bitmap& source);
	void copyValuesFrom(const Bitmap& source);
	void clearPixelsIfNecessary();

	Pixel** pixels{nullptr};
	std::string name;
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;
	int numberOfZeroBytes{0};
};

