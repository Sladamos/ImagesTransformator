#pragma once
#include "ImagesLoader.h"
#include "Bmp24.h"
class Bmp24Loader : public ImagesLoader
{
private:
	void loadPixels(std::ifstream& bitmapFile, Bmp24Content& bitmap);
	void loadPixel(std::ifstream& bitmapFile, Pixel& bitmap);
	void prepareAndLoadContent(std::ifstream& bitmapFile, Image* image) override;
};

