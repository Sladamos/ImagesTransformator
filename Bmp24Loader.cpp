#include "Bmp24Loader.h"

void Bmp24Loader::prepareAndLoadContent(std::ifstream& bitmapFile, Bitmap* bitmap)
{
	int bitmapWidth = bitmap->getInfoHeader().bitmapWidth, bitmapHeight = bitmap->getInfoHeader().bitmapHeight;
	bitmap->createUninitializedPixels();
	bitmap->setNumberOfZeroBytes(bitmap->getInfoHeader().imageSize / bitmapHeight - bitmap->getInfoHeader().bitsPerPixel / 8 * bitmapWidth);
	bitmapFile.seekg(bitmap->getFileHeader().offsetData, bitmapFile.beg);
	loadPixels(bitmapFile, bitmap);
}

void Bmp24Loader::loadPixels(std::ifstream& bitmapFile, Bitmap* bitmap)
{
	Pixel** pixels = bitmap->getPixels();
	int bitmapWidth = bitmap->getInfoHeader().bitmapWidth, bitmapHeight = bitmap->getInfoHeader().bitmapHeight;
	for (int y = 0; y < bitmapHeight; y++)
	{
		for (int x = 0; x < bitmapWidth; x++)
			loadPixel(bitmapFile, pixels[y][x]);
		bitmapFile.seekg(bitmap->getNumberOfZeroBytes(), bitmapFile.cur);
	}
}

void Bmp24Loader::loadPixel(std::ifstream& bitmapFile, Pixel& pixel)
{
	bitmapFile.read(reinterpret_cast<char*>(&pixel.B), sizeof(pixel.B));
	bitmapFile.read(reinterpret_cast<char*>(&pixel.G), sizeof(pixel.G));
	bitmapFile.read(reinterpret_cast<char*>(&pixel.R), sizeof(pixel.R));
}