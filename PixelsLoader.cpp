#include "PixelsLoader.h"

void PixelsLoader::createAndLoadPixels(Bitmap& bitmap)
{
	int bitmapWidth = bitmap.getInfoHeader().bitmapWidth, bitmapHeight = bitmap.getInfoHeader().bitmapHeight;
	bitmap.createUninitializedPixels();
	bitmap.setNumberOfZeroBytes(bitmap.getInfoHeader().imageSize / bitmapHeight - bitmap.getInfoHeader().bitsPerPixel / 8 * bitmapWidth);
	loadFromFile(bitmap);
}

void PixelsLoader::loadFromFile(Bitmap& bitmap)
{
	std::ifstream bitmapFile(std::string("./gfx/") + bitmap.getName(), std::ios_base::binary);
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
			loadPixel(bitmapFile, pixels[y][x]);
		bitmapFile.seekg(bitmap.getNumberOfZeroBytes(), bitmapFile.cur);
	}
}

void PixelsLoader::loadPixel(std::ifstream& bitmapFile, Pixel& pixel)
{
	bitmapFile.read(reinterpret_cast<char*>(&pixel.B), sizeof(pixel.B));
	bitmapFile.read(reinterpret_cast<char*>(&pixel.G), sizeof(pixel.G));
	bitmapFile.read(reinterpret_cast<char*>(&pixel.R), sizeof(pixel.R));
}