#include <cmath>
#include "Pixel.h"
#include "Bitmap.h"
#include "MasksOperator.h"

int Pixel::transformateColorByMask(const Bitmap& sourceBitmap, const Mask& mask, Color color) const
{
	int colorValue = 0, maskSize = mask.getSize();

	for (int i = y - maskSize / 2, z = 0; i <= y + maskSize / 2; i++, z++)
		for (int j = x - maskSize / 2, f = 0; j <= x + maskSize / 2; j++, f++)
		{
			Pixel sourcePixel = createSourcePixel(sourceBitmap, i, j);
			colorValue += sourcePixel.getColorValue(color) * mask[z * maskSize + f];
		}
	return colorValue;
}

Pixel Pixel::createSourcePixel(const Bitmap& sourceBitmap, int row, int column) const
{
	Pixel sourcePixel, blackPixel;
	if (row < 0 || column < 0 || column >= sourceBitmap.getInfoHeader().bitmapWidth || row >= sourceBitmap.getInfoHeader().bitmapHeight)
		return Pixel();
	else
		return sourceBitmap.getPixels()[row][column];
}

uint8_t Pixel::getColorValue(Color color) const
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