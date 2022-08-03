#include <cmath>
#include "Pixel.h"
#include "MasksOperator.h"

void Pixel::transformate(Pixel** sourcePixels, int maxWidth, int maxHeight)
{
	int valR = 0, valG = 0, valB = 0;

	for (int m = 0; m < MasksOperator::numberOfMasks; m++)
	{
		valR += pow(transformateRedByMask(sourcePixels, maxWidth, maxHeight, MasksOperator::getMask(m)),2);
		valG += pow(transformateGreenByMask(sourcePixels, maxWidth, maxHeight, MasksOperator::getMask(m)),2);
		valB += pow(transformateBlueByMask(sourcePixels, maxWidth, maxHeight, MasksOperator::getMask(m)),2);
	}

	valR = sqrt(valR), valB = sqrt(valB), valG = sqrt(valG);
	R = valR > 255 ? 255 : valR;
	G = valG > 255 ? 255 : valG;
	B = valB > 255 ? 255 : valB;
}

int Pixel::transformateRedByMask(Pixel** sourcePixels, int maxWidth, int maxHeight, const std::vector<int>& mask)
{
	int tempR = 0;
	Pixel sourcePixel, blackPixel;

	for (int i = y - MasksOperator::maskSize / 2, z = 0; i <= y + MasksOperator::maskSize / 2; i++, z++)
		for (int j = x - MasksOperator::maskSize / 2, f = 0; j <= x + MasksOperator::maskSize / 2; j++, f++)
		{
			if (i < 0 || j < 0 || j >= maxWidth || i >= maxHeight)
				sourcePixel = blackPixel;
			else
				sourcePixel = sourcePixels[i][j];

			tempR += sourcePixel.R * mask[z * MasksOperator::maskSize + f];
		}
	return tempR;
}

int Pixel::transformateGreenByMask(Pixel** sourcePixels, int maxWidth, int maxHeight, const std::vector<int>& mask)
{
	int tempG = 0;
	Pixel sourcePixel, blackPixel;

	for (int i = y - MasksOperator::maskSize / 2, z = 0; i <= y + MasksOperator::maskSize / 2; i++, z++)
		for (int j = x - MasksOperator::maskSize / 2, f = 0; j <= x + MasksOperator::maskSize / 2; j++, f++)
		{
			if (i < 0 || j < 0 || j >= maxWidth || i >= maxHeight)
				sourcePixel = blackPixel;
			else
				sourcePixel = sourcePixels[i][j];

			tempG += sourcePixel.G * mask[z * MasksOperator::maskSize + f];
		}
	return tempG;
}

int Pixel::transformateBlueByMask(Pixel** sourcePixels, int maxWidth, int maxHeight, const std::vector<int>& mask)
{
	int tempB = 0;
	Pixel sourcePixel, blackPixel;

	for (int i = y - MasksOperator::maskSize / 2, z = 0; i <= y + MasksOperator::maskSize / 2; i++, z++)
		for (int j = x - MasksOperator::maskSize / 2, f = 0; j <= x + MasksOperator::maskSize / 2; j++, f++)
		{
			if (i < 0 || j < 0 || j >= maxWidth || i >= maxHeight)
				sourcePixel = blackPixel;
			else
				sourcePixel = sourcePixels[i][j];

			tempB += sourcePixel.B * mask[z * MasksOperator::maskSize + f];
		}
	return tempB;
}