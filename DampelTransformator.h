#pragma once
#include "Transformator.h"
class DampelTransformator : public Transformator
{
public:
	DampelTransformator(Image*& sourceImage);
private:
	Pixel transformatePixel(const Pixel& sourcePixel) override;
	int transformateColorByMask(const Pixel& sourcePixel, const Mask& mask, Pixel::Color color);
	uint8_t transformatePixelColor(const Pixel& sourcePixel, Pixel::Color color);
	Pixel getNeighbourPixel(int row, int column);
};

