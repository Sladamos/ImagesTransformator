#pragma once
#include "ImagesLoader.h"
#include "Bmp24.h"
class Bmp24Loader : public ImagesLoader<Bmp24>
{
private:
	void loadPixels(std::ifstream& bitmapFile, Bmp24Content& bitmap);
	void loadPixel(std::ifstream& bitmapFile, Pixel& bitmap);
	void prepareAndLoadContent(std::ifstream& bitmapFile, Bmp24* bmp24) override;
};

