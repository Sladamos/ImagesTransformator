#pragma once
#include "ImageContent.h"
class Bmp24Content : public ImageContent
{
public:
	int getNumberOfZeroBytes() const;
	Pixel** getPixels() const;
	void setNumberOfZeroBytes(int numberOfZeroBytes);
	void createUninitializedPixels();

	Pixel& operator()(int y, int x) const;
private:
	void clearPixelsIfNecessary();

	Pixel** pixels{ nullptr };
	int numberOfZeroBytes{ 0 };
};

