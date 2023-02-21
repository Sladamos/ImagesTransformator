#include "Bmp24.h"

Bmp24::Bmp24(Bmp24* source, const std::string& bitmapName) : Image::Image(source, bitmapName)
{
	numberOfZeroBytes = source->numberOfZeroBytes;
	createUninitializedPixels();
}

void Bmp24::createUninitializedPixels()
{
	clearPixelsIfNecessary();
	const Bmp24Header& bmp24Header = dynamic_cast<const Bmp24Header&>(getImageHeader());
	pixels = new Pixel* [bmp24Header.bitmapHeight];
	for (int y = 0; y < bmp24Header.bitmapHeight; y++)
	{
		pixels[y] = new Pixel[bmp24Header.bitmapWidth];
		for (int x = 0; x < bmp24Header.bitmapWidth; x++)
		{
			pixels[y][x].x = x;
			pixels[y][x].y = y;
		}
	}
}

void Bmp24::clearPixelsIfNecessary()
{
	const Bmp24Header& bmp24Header = dynamic_cast<const Bmp24Header&>(getImageHeader());
	if (pixels != nullptr)
	{
		for (int i = 0; i < bmp24Header.bitmapHeight; i++)
			delete[] pixels[i];
		delete[] pixels;
	}
	pixels = nullptr;
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

Bmp24::~Bmp24()
{
	clearPixelsIfNecessary();
}
