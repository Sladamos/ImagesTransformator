#include "SobelTransformator.h"
#include "SobelMasksOperator.h"

SobelTransformator::SobelTransformator() : Transformator(new SobelMasksOperator()) {}

Pixel SobelTransformator::transformatePixel(const Bitmap& sourceBitmap, const Pixel& sourcePixel)
{
	Pixel newPixel;
	int valR = 0, valG = 0, valB = 0, numberOfMasks = masksOperator->getNumberOfMasks();
	for (const Mask& mask : masksOperator->getMasks())
	{
		valR += pow(sourcePixel.transformateColorByMask(sourceBitmap, mask, Pixel::Color::red), 2);
		valG += pow(sourcePixel.transformateColorByMask(sourceBitmap, mask, Pixel::Color::green), 2);
		valB += pow(sourcePixel.transformateColorByMask(sourceBitmap, mask, Pixel::Color::blue), 2);
	}

	valR = sqrt(valR), valB = sqrt(valB), valG = sqrt(valG);
	newPixel.R = valR > 255 ? 255 : valR;
	newPixel.G = valG > 255 ? 255 : valG;
	newPixel.B = valB > 255 ? 255 : valB;
	
	return newPixel;
}