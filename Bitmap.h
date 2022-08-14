#pragma once
#include "Image.h"
#include "Pixel.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
class Bitmap : public Image
{
public:
	Bitmap() = default;
	Bitmap(Bitmap* source, const std::string& bitmapName);
	~Bitmap();
	int getNumberOfZeroBytes() const;
	BitmapFileHeader getFileHeader() const;
	BitmapInfoHeader getInfoHeader() const;
	Pixel** getPixels() const;
	void setNumberOfZeroBytes(int numberOfZeroBytes);
	void setFileHeader(const BitmapFileHeader& fileHeader);
	void setInfoHeader(const BitmapInfoHeader& infoHeader);
	void createUninitializedPixels();
	void clear() override;
private:
	void clearPixelsIfNecessary();

	Pixel** pixels{nullptr};
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;
	int numberOfZeroBytes{0};
};

