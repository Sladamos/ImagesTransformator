#include "Bmp24.h"

Bmp24::Bmp24(Bmp24* source, const std::string& bitmapName) : Image::Image(source, bitmapName)
{
	numberOfZeroBytes = source->numberOfZeroBytes;
	createUninitializedPixels();
}

void Bmp24::createUninitializedPixels()
{
	clearPixelsIfNecessary();
	pixels = new Pixel* [infoHeader.bitmapHeight];
	for (int y = 0; y < infoHeader.bitmapHeight; y++)
	{
		pixels[y] = new Pixel[infoHeader.bitmapWidth];
		for (int x = 0; x < infoHeader.bitmapWidth; x++)
		{
			pixels[y][x].x = x;
			pixels[y][x].y = y;
		}
	}
}

void Bmp24::clearPixelsIfNecessary()
{
	if (pixels != nullptr)
	{
		for (int i = 0; i < infoHeader.bitmapHeight; i++)
			delete[] pixels[i];
		delete[] pixels;
	}
	pixels = nullptr;
}

Bmp24FileHeader Bmp24::getFileHeader() const
{
	return fileHeader;
}

Bmp24InfoHeader Bmp24::getInfoHeader() const
{
	return infoHeader;
}

Pixel** Bmp24::getPixels() const
{
	return pixels;
}

int Bmp24::getNumberOfZeroBytes() const
{
	return numberOfZeroBytes;
}

void Bmp24::setNumberOfZeroBytes(int numberOfZeroBytes)
{
	this->numberOfZeroBytes = numberOfZeroBytes;
}

std::string Bmp24::toString()
{
	return fileHeader.toString() + infoHeader.toString();
}

Bmp24::~Bmp24()
{
	clearPixelsIfNecessary();
}
