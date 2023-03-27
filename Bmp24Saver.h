#pragma once
#include "ImagesSaver.h"
#include "Bmp24.h"
class Bmp24Saver : public ImagesSaver<Bmp24Header, Bmp24Content>
{
private:
	void writeImageHeader(std::ofstream& imageFile, const Bmp24Header& imageHeader) override;
	void writeImageContent(std::ofstream& imageFile, const Bmp24Content& imageContent) override;
	void writePixel(std::ofstream& bitmapFile, const Pixel& pixel);
};

