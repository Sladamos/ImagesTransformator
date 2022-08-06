#include <cmath>
#include "Pixel.h"
#include "Bitmap.h"
#include "MasksOperator.h"

void Pixel::transformate(const Bitmap& sourceBitmap)
{
	int valR = 0, valG = 0, valB = 0;

	for (int m = 0; m < MasksOperator::numberOfMasks; m++)
	{
		valR += pow(transformateByMask(sourceBitmap, MasksOperator::getMask(m), Color::red),2);
		valG += pow(transformateByMask(sourceBitmap, MasksOperator::getMask(m), Color::green),2);
		valB += pow(transformateByMask(sourceBitmap, MasksOperator::getMask(m), Color::blue),2);
	}

	valR = sqrt(valR), valB = sqrt(valB), valG = sqrt(valG);
	R = valR > 255 ? 255 : valR;
	G = valG > 255 ? 255 : valG;
	B = valB > 255 ? 255 : valB;
}

int Pixel::transformateByMask(const Bitmap& sourceBitmap, const std::vector<int>& mask, Color color)
{
	int colorValue = 0;

	for (int i = y - MasksOperator::maskSize / 2, z = 0; i <= y + MasksOperator::maskSize / 2; i++, z++)
		for (int j = x - MasksOperator::maskSize / 2, f = 0; j <= x + MasksOperator::maskSize / 2; j++, f++)
		{
			Pixel sourcePixel = createSourcePixel(sourceBitmap, i, j);
			colorValue += sourcePixel.getColorValue(color) * mask[z * MasksOperator::maskSize + f];
		}
	return colorValue;
}

Pixel Pixel::createSourcePixel(const Bitmap& sourceBitmap, int row, int column)
{
	Pixel sourcePixel, blackPixel;
	if (row < 0 || column < 0 || column >= sourceBitmap.getInfoHeader().bitmapWidth || row >= sourceBitmap.getInfoHeader().bitmapHeight)
		return Pixel();
	else
		return sourceBitmap.getPixels()[row][column];
}

uint8_t Pixel::getColorValue(Color color)
{
	switch (color)
	{
	case Color::red:
		return R;
	case Color::green:
		return G;
	case Color::blue:
		return B;
	}
}