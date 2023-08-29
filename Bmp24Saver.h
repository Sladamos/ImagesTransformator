#pragma once
#include "ImagesSaver.h"
#include "Bmp24.h"
class Bmp24Saver : public ImagesSaver<Bmp24, Bmp24Header, Bmp24Content>
{
public:
	Bmp24Saver(const std::string& directory_path);
private:
	void writeImageHeader(std::ofstream& imageFile, std::shared_ptr<Bmp24Header> imageHeader) override;
	void writeImageContent(std::ofstream& imageFile, std::shared_ptr<Bmp24Content> imageContent) override;
	void writePixel(std::ofstream& bitmapFile, const Pixel& pixel);
};

