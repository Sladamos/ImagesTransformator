#include "Transformator.h"

Transformator::Transformator(MasksOperator* masksOperator, Image*& sourceImage) : masksOperator(masksOperator),
sourceImage(sourceImage), masks(masksOperator->getMasks()) {}

Image* Transformator::transformateImage(const std::string& outputName, const std::string& imageFormat)
{
	Image* output = nullptr;
	if (imageFormat == "Bmp24")
		output = transformateBmp24(outputName);
	return output;
}

Bmp24* Transformator::transformateBmp24(const std::string& outputName)
{
	Bmp24* output = new Bmp24(reinterpret_cast<Bmp24*>(sourceImage), outputName);
	Bmp24InfoHeader infoHeader = output->getInfoHeader();
	Pixel** pixels = output->getPixels();

	for (int y = 0; y < infoHeader.bitmapHeight; y++)
		for (int x = 0; x < infoHeader.bitmapWidth; x++)
			pixels[y][x] = transformatePixel(pixels[y][x]);

	return output;
}

Pixel Transformator::transformatePixel(const Pixel& sourcePixel)
{
	return sourcePixel;
}

Transformator::~Transformator()
{
	delete masksOperator;
}