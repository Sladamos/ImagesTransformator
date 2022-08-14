#pragma once
#include "ImagesLoader.h"
#include "Bitmap.h"
class Bmp24Loader : public ImagesLoader
{
private:
	void loadPixels(std::ifstream& bitmapFile, Bitmap* bitmap);
	void loadPixel(std::ifstream& bitmapFile, Pixel& bitmap);
	void prepareAndLoadContent(std::ifstream& bitmapFile, Bitmap* bitmap) override;
};

