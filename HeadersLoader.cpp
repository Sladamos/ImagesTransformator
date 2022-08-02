#include "HeadersLoader.h"
using namespace std;

BitmapFileHeader HeadersLoader::fileHeader{};
BitmapInfoHeader HeadersLoader::infoHeader{};

BitmapFileHeader HeadersLoader::getFileHeader()
{
	return fileHeader;
}

BitmapInfoHeader HeadersLoader::getInfoHeader()
{
	return infoHeader;
}

void HeadersLoader::loadHeaders(const string& bitmapName)
{
	ifstream bitmapFile(bitmapName.c_str(), ios_base::binary);
	resetHeaders();
	if (bitmapFile.is_open())
	{
		loadBmpFileHeader(bitmapFile);
		loadBmpInfoHeader(bitmapFile);
		bitmapFile.close();
	}
}

void HeadersLoader::resetHeaders()
{
	fileHeader = BitmapFileHeader();
	infoHeader = BitmapInfoHeader();
}

void HeadersLoader::loadBmpFileHeader(ifstream& bitmapFile)
{
	bitmapFile.read(reinterpret_cast<char*>(&fileHeader.fileType), 2);
	bitmapFile.read(reinterpret_cast<char*>(&fileHeader.fileSize), 4);
	bitmapFile.read(reinterpret_cast<char*>(&fileHeader.reservedField1), 2);
	bitmapFile.read(reinterpret_cast<char*>(&fileHeader.reservedField2), 2);
	bitmapFile.read(reinterpret_cast<char*>(&fileHeader.offsetData), 4);
}

void HeadersLoader::loadBmpInfoHeader(ifstream& bitmapFile)
{
	bitmapFile.read(reinterpret_cast<char*>(&infoHeader.headerSize), 4);
	bitmapFile.read(reinterpret_cast<char*>(&infoHeader.bitmapWidth), 4);
	bitmapFile.read(reinterpret_cast<char*>(&infoHeader.bitmapHeight), 4);
	bitmapFile.read(reinterpret_cast<char*>(&infoHeader.planes), 2);
	bitmapFile.read(reinterpret_cast<char*>(&infoHeader.bitsPerPixel), 2);
	bitmapFile.read(reinterpret_cast<char*>(&infoHeader.compressionAlgorithm), 4);
	bitmapFile.read(reinterpret_cast<char*>(&infoHeader.imageSize), 4);
	bitmapFile.read(reinterpret_cast<char*>(&infoHeader.horizontalResolution), 4);
	bitmapFile.read(reinterpret_cast<char*>(&infoHeader.verticalResolution), 4);
	bitmapFile.read(reinterpret_cast<char*>(&infoHeader.colorsUsed), 4);
	bitmapFile.read(reinterpret_cast<char*>(&infoHeader.colorsImportant), 4);
}
