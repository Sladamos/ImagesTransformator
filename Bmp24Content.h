#pragma once
#include <memory>
#include "ImageContent.h"
#include "Pixel.h"
class Bmp24Content : public ImageContent
{
public:
	int getNumberOfZeroBytes() const;
	Pixels getPixels() const;
	void setNumberOfZeroBytes(int numberOfZeroBytes);
	void createUninitializedPixels();

	Pixel& operator()(int y, int x) const;
private:
	Pixels pixels;
	int numberOfZeroBytes{ 0 };
};


