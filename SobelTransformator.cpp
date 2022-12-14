#include <cmath>
#include "SobelTransformator.h"
#include "SobelMasksOperator.h"

SobelTransformator::SobelTransformator(Image*& sourceImage) : Transformator(new SobelMasksOperator(), sourceImage) {}

Pixel SobelTransformator::transformatePixel(const Pixel& sourcePixel)
{	
	Pixel newPixel;
	newPixel.R = transformatePixelColor(sourcePixel, Pixel::Color::red);
	newPixel.G = transformatePixelColor(sourcePixel, Pixel::Color::green);
	newPixel.B = transformatePixelColor(sourcePixel, Pixel::Color::blue);
	return newPixel;
}

uint8_t SobelTransformator::transformatePixelColor(const Pixel& sourcePixel, Pixel::Color color)
{
	int colorValue = 0;
	for (const Mask& mask : masks)
		colorValue += pow(transformateColorByMask(sourcePixel, mask, color), 2);
	colorValue = sqrt(colorValue);
	return colorValue > 255 ? 255 : colorValue;
}

int SobelTransformator::transformateColorByMask(const Pixel& sourcePixel, const Mask& mask, Pixel::Color color)
{
	int colorValue = 0, maskSize = mask.getSize(), y = sourcePixel.y, x = sourcePixel.x;

	for (int i = y - maskSize / 2, z = 0; i <= y + maskSize / 2; i++, z++)
		for (int j = x - maskSize / 2, f = 0; j <= x + maskSize / 2; j++, f++)
		{
			Pixel neighbourPixel = getNeighbourPixel(i, j);
			colorValue += neighbourPixel.getColorValue(color) * mask[z * maskSize + f];
		}
	return colorValue;
}

Pixel SobelTransformator::getNeighbourPixel(int row, int column)
{
	Bmp24* sourceBmp24 = reinterpret_cast<Bmp24*>(sourceImage);
	Pixel sourcePixel, blackPixel;
	if (row < 0 || column < 0 || column >= sourceBmp24->getInfoHeader().bitmapWidth || row >= sourceBmp24->getInfoHeader().bitmapHeight)
		return Pixel();
	else
		return sourceBmp24->getPixels()[row][column];
}
