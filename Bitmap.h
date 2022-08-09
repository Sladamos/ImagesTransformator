#pragma once
#include <string>
#include "Pixel.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
class Bitmap
{
public:
	Bitmap() = default;
	Bitmap(const Bitmap& source, const std::string& bitmapName);
	~Bitmap();
	friend std::ostream& operator<<(std::ostream& os, const Bitmap& fileHeader);
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
	void clearPixelsIfNecessary();
private:
	void transformatePixels(const Bitmap& source);

	Pixel** pixels{nullptr};
	std::string name;
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;
	int numberOfZeroBytes{0};
};

