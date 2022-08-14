#pragma once
#include "Image.h"
#include "Pixel.h"
#include "Bmp24FileHeader.h"
#include "Bmp24InfoHeader.h"
class Bmp24 : public Image
{
public:
	Bmp24() = default;
	Bmp24(Bmp24* source, const std::string& bitmapName);
	~Bmp24();
	int getNumberOfZeroBytes() const;
	Bmp24FileHeader getFileHeader() const;
	Bmp24InfoHeader getInfoHeader() const;
	Pixel** getPixels() const;
	void setNumberOfZeroBytes(int numberOfZeroBytes);
	void setFileHeader(const Bmp24FileHeader& fileHeader);
	void setInfoHeader(const Bmp24InfoHeader& infoHeader);
	void createUninitializedPixels();
	void clear() override;
	std::string toString() override;
private:
	void clearPixelsIfNecessary();

	Pixel** pixels{nullptr};
	Bmp24FileHeader fileHeader;
	Bmp24InfoHeader infoHeader;
	int numberOfZeroBytes{0};
};

