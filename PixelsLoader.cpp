#include "PixelsLoader.h"

void PixelsLoader::createAndLoadPixels(Bitmap& bitmap)
{
	int bitmapWidth = bitmap.getInfoHeader().bitmapWidth, bitmapHeight = bitmap.getInfoHeader().bitmapHeight;
	bitmap.setPixels(createUninitializedPixels(bitmapWidth, bitmapHeight));
	bitmap.setNumberOfZeroBytes(bitmap.getInfoHeader().imageSize / bitmapHeight - bitmap.getInfoHeader().bitsPerPixel / 8 * bitmapWidth);
	loadFromFile(bitmap);
}

Pixel** PixelsLoader::createUninitializedPixels(int width, int height)
{
	Pixel** pixels = new Pixel* [height];
	for (int i = 0; i < height; i++)
		pixels[i] = new Pixel[width];
	return pixels;
}

void PixelsLoader::loadFromFile(Bitmap& bitmap)
{
	std::ifstream bitmapFile(bitmap.getName().c_str(), std::ios_base::binary);
	if (bitmapFile.is_open())
	{
		bitmapFile.seekg(bitmap.getFileHeader().offsetData, bitmapFile.beg);
		loadPixels(bitmapFile, bitmap);
		bitmapFile.close();
	}
}

void PixelsLoader::loadPixels(std::ifstream& bitmapFile, Bitmap& bitmap)
{
	Pixel** pixels = bitmap.getPixels();
	int bitmapWidth = bitmap.getInfoHeader().bitmapWidth, bitmapHeight = bitmap.getInfoHeader().bitmapHeight;
	for (int y = 0; y < bitmapHeight; y++)
	{
		for (int x = 0; x < bitmapWidth; x++)
		{
			bitmapFile.read(reinterpret_cast<char*>(&pixels[y][x].B), sizeof(pixels[y][x].B));
			bitmapFile.read(reinterpret_cast<char*>(&pixels[y][x].G), sizeof(pixels[y][x].G));
			bitmapFile.read(reinterpret_cast<char*>(&pixels[y][x].R), sizeof(pixels[y][x].R));
		}
		bitmapFile.seekg(bitmap.getNumberOfZeroBytes(), bitmapFile.cur);
	}
}