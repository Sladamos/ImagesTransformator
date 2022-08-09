#include "Transformator.h"

Transformator::Transformator(MasksOperator* masksOperator) : masksOperator(masksOperator) {}

Bitmap* Transformator::transformateBitmap(const Bitmap& source, const std::string& outputName)
{
	Bitmap* output = new Bitmap(source, outputName);
	BitmapInfoHeader infoHeader = output->getInfoHeader();
	Pixel** pixels = output->getPixels();

	for (int y = 0; y < infoHeader.bitmapHeight; y++)
		for (int x = 0; x < infoHeader.bitmapWidth; x++)
			pixels[y][x] = transformatePixel(source, pixels[y][x]);

	return output;
}

Transformator::~Transformator()
{
	delete masksOperator;
}