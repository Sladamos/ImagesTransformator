#include "Bmp24Content.h"

int Bmp24Content::getNumberOfZeroBytes() const
{
	return numberOfZeroBytes;
}

Pixels Bmp24Content::getPixels() const
{
    return pixels;
}

void Bmp24Content::setNumberOfZeroBytes(int numberOfZeroBytes)
{
    this->numberOfZeroBytes = numberOfZeroBytes;
}

void Bmp24Content::createUninitializedPixels()
{
	pixels = Pixels(new PixelsRow[height]);
	for (int y = 0; y < height; y++)
	{
		pixels[y] = PixelsRow(new Pixel[width]);
		for (int x = 0; x < width; x++)
		{
			pixels[y][x].x = x;
			pixels[y][x].y = y;
		}
	}
}

Pixel& Bmp24Content::operator()(int y, int x) const
{
    return pixels[y][x];
}
