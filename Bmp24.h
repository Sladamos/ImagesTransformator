#pragma once
#include "Image.h"
#include "Pixel.h"
#include "Bmp24Header.h"
#include "Bmp24Content.h"
class Bmp24 : public Image
{
public:
	Bmp24() = default;
	Bmp24(Bmp24* source, const std::string& bitmapName);
	~Bmp24();
	int getNumberOfZeroBytes() const;
	Pixel** getPixels() const;
	void setNumberOfZeroBytes(int numberOfZeroBytes);
	void createUninitializedPixels();
private:
	void clearPixelsIfNecessary();

	Pixel** pixels{nullptr};
	int numberOfZeroBytes{0};
};

