#include "Bitmap.h"

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

void Bitmap::setPixels(Pixel** pixels)
{
	this->pixels = pixels;
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
	if (pixels != nullptr)
	{
		for (int i = 0; i < infoHeader.bitmapHeight; i++)
			delete [] pixels[i];
		delete [] pixels;
	}
}