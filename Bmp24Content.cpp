#include "Bmp24Content.h"

Bmp24Content::Bmp24Content(const Bmp24Content& content) : ImageContent(content)
{
	numberOfZeroBytes = content.numberOfZeroBytes;
	createUninitializedPixels();
	int height = getHeight();
	int width = getWidth();
	auto sourcePixels = content.getPixels();
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			pixels[y][x] = sourcePixels[y][x];
		}
	}
}

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
