#include "Bitmap.h"

std::string Bitmap::getName() const
{
	return name;
}

BitmapFileHeader Bitmap::getFileHeader()
{
	return fileHeader;
}

BitmapInfoHeader Bitmap::getInfoHeader()
{
	return infoHeader;
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