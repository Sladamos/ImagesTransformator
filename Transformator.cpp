#include "Transformator.h"

Transformator::Transformator(MasksOperator* masksOperator, Bitmap*& sourceBitmap) : masksOperator(masksOperator),
sourceBitmap(sourceBitmap), masks(masksOperator->getMasks()) {}

Bitmap* Transformator::transformateImage(const std::string& outputName)
{
	Bitmap* output = new Bitmap(sourceBitmap, outputName);
	BitmapInfoHeader infoHeader = output->getInfoHeader();
	Pixel** pixels = output->getPixels();

	for (int y = 0; y < infoHeader.bitmapHeight; y++)
		for (int x = 0; x < infoHeader.bitmapWidth; x++)
			pixels[y][x] = transformatePixel(pixels[y][x]);

	return output;
}

Transformator::~Transformator()
{
	delete masksOperator;
}