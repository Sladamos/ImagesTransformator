#pragma once
#include "ImagesLoader.h"
#include "Bmp24.h"
class Bmp24Loader : public ImagesLoader<Bmp24>
{
public:
	Bmp24Loader(const std::string& directory_path);
private:
	void loadPixels(std::ifstream& bitmapFile, Bmp24Content& bitmap);
	void loadPixel(std::ifstream& bitmapFile, Pixel& bitmap);
	void prepareAndLoadContent(std::ifstream& bitmapFile, std::shared_ptr<Bmp24> bmp24) override;
};

