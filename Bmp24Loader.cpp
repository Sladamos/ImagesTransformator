#include "Bmp24Loader.h"

void Bmp24Loader::prepareAndLoadContent(std::ifstream& bitmapFile, Bmp24* bitmap)
{
	auto bitmapHeader = bitmap->getImageHeader();
	auto bitmapContent = bitmap->getImageContent();
	bitmapContent->setWidth(bitmapHeader->bitmapWidth);
	bitmapContent->setHeight(bitmapHeader->bitmapHeight);
	int bitmapWidth = bitmapContent->getWidth(), bitmapHeight = bitmapContent->getHeight();

	bitmapContent->createUninitializedPixels();
	bitmapContent->setNumberOfZeroBytes(bitmapHeader->imageSize / bitmapHeight - bitmapHeader->bitsPerPixel / 8 * bitmapWidth);
	bitmapFile.seekg(bitmapHeader->offsetData, bitmapFile.beg);
	loadPixels(bitmapFile, *bitmapContent);
}

void Bmp24Loader::loadPixels(std::ifstream& bitmapFile, Bmp24Content& bitmapContent)
{
	Pixels pixels = bitmapContent.getPixels();
	int bitmapWidth = bitmapContent.getWidth(), bitmapHeight = bitmapContent.getHeight();
	for (int y = 0; y < bitmapHeight; y++)
	{
		for (int x = 0; x < bitmapWidth; x++)
			loadPixel(bitmapFile, pixels[y][x]);
		bitmapFile.seekg(bitmapContent.getNumberOfZeroBytes(), bitmapFile.cur);
	}
}

void Bmp24Loader::loadPixel(std::ifstream& bitmapFile, Pixel& pixel)
{
	bitmapFile.read(reinterpret_cast<char*>(&pixel.B), sizeof(pixel.B));
	bitmapFile.read(reinterpret_cast<char*>(&pixel.G), sizeof(pixel.G));
	bitmapFile.read(reinterpret_cast<char*>(&pixel.R), sizeof(pixel.R));
}