#include "Bmp24Transformator.h"

Bmp24Transformator::Bmp24Transformator(const std::vector<Mask>& masks) : Transformator(masks)
{
}

std::shared_ptr<Bmp24> Bmp24Transformator::transformateImage(std::shared_ptr<Bmp24> source)
{
	std::shared_ptr<Bmp24> output = nullptr;
	currentSource = source;
	if(source != nullptr)
		output = transformSource();
	currentSource = nullptr;
	return output;
}

std::shared_ptr<Bmp24> Bmp24Transformator::transformSource()
{
	std::shared_ptr<Bmp24> output = std::shared_ptr<Bmp24>(new Bmp24(*currentSource));
	auto content = currentSource->getImageContent();
	int width = content->getWidth(), height = content->getHeight();
	Pixels outputPixels = output->getImageContent()->getPixels();
	Pixels sourcePixels = content->getPixels();

	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			outputPixels[y][x] = transformatePixel(sourcePixels[y][x]);

	return output;
}

Pixel Bmp24Transformator::transformatePixel(const Pixel& sourcePixel)
{
	Pixel newPixel;
	newPixel.R = transformatePixelColor(sourcePixel, Pixel::Color::red);
	newPixel.G = transformatePixelColor(sourcePixel, Pixel::Color::green);
	newPixel.B = transformatePixelColor(sourcePixel, Pixel::Color::blue);
	return newPixel;
}

uint8_t Bmp24Transformator::transformatePixelColor(const Pixel& sourcePixel, Pixel::Color color)
{
	int colorValue = 0;
	for (const Mask& mask : masks)
		colorValue += pow(transformateColorByMask(sourcePixel, mask, color), 2);
	colorValue = sqrt(colorValue);
	return colorValue > 255 ? 255 : colorValue;
}

int Bmp24Transformator::transformateColorByMask(const Pixel& sourcePixel, const Mask& mask, Pixel::Color color)
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

Pixel Bmp24Transformator::getNeighbourPixel(int row, int column)
{
	auto content = currentSource->getImageContent();
	if (row < 0 || column < 0 || column >= content->getWidth() || row >= content->getHeight())
		return Pixel();
	else
		return content->getPixels()[row][column];
}