#include "Bitmap.h"

void Bitmap::sobelTransformationFrom(const Bitmap& source)
{
	copyValuesFrom(source);
	transformatePixels(source);
}

void Bitmap::copyValuesFrom(const Bitmap& source)
{
	clearPixelsIfNecessary();
	fileHeader = source.fileHeader;
	infoHeader = source.infoHeader;
	numberOfZeroBytes = source.numberOfZeroBytes;
	createUninitializedPixels();
}

void Bitmap::clearPixelsIfNecessary()
{
	if (pixels != nullptr)
	{
		for (int i = 0; i < infoHeader.bitmapHeight; i++)
			delete[] pixels[i];
		delete[] pixels;
	}
}

void Bitmap::createUninitializedPixels()
{
	pixels = new Pixel* [infoHeader.bitmapHeight];
	for (int y = 0; y < infoHeader.bitmapHeight; y++)
	{
		pixels[y] = new Pixel[infoHeader.bitmapWidth];
		for (int x = 0; x < infoHeader.bitmapWidth; x++)
		{
			pixels[y][x].x = x;
			pixels[y][x].y = y;
		}
	}
}

void Bitmap::transformatePixels(const Bitmap& source)
{
	for (int y = 0; y < infoHeader.bitmapHeight; y++)
		for (int x = 0; x < infoHeader.bitmapWidth; x++)
			pixels[y][x].transformate(source);
			
}

std::string Bitmap::getName() const
{
	return name;
}

BitmapFileHeader Bitmap::getFileHeader() const
{
	return fileHeader;
}

BitmapInfoHeader Bitmap::getInfoHeader() const
{
	return infoHeader;
}

Pixel** Bitmap::getPixels() const
{
	return pixels;
}

int Bitmap::getNumberOfZeroBytes() const
{
	return numberOfZeroBytes;
}

void Bitmap::setNumberOfZeroBytes(int numberOfZeroBytes)
{
	this->numberOfZeroBytes = numberOfZeroBytes;
}

void Bitmap::setName(const std::string& name)
{
	this->name = name;
}

void Bitmap::setFileHeader(const BitmapFileHeader& fileHeader)
{
	this->fileHeader = fileHeader;
}

void Bitmap::setInfoHeader(const BitmapInfoHeader& infoHeader)
{
	this->infoHeader = infoHeader;
}

void Bitmap::resetHeaders()
{
	fileHeader = BitmapFileHeader();
	infoHeader = BitmapInfoHeader();
}

Bitmap::~Bitmap()
{
	clearPixelsIfNecessary();
}