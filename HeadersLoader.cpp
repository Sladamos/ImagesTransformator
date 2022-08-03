#include "HeadersLoader.h"
using namespace std;

void HeadersLoader::loadHeaders(Bitmap& bitmap)
{
	string bitmapName = bitmap.getName();
	ifstream bitmapFile(bitmapName.c_str(), ios_base::binary);
	bitmap.resetHeaders();
	if (bitmapFile.is_open())
	{
		bitmap.setFileHeader(loadBmpFileHeader(bitmapFile));
		bitmap.setInfoHeader(loadBmpInfoHeader(bitmapFile));
		bitmapFile.close();
	}
}

BitmapFileHeader HeadersLoader::loadBmpFileHeader(ifstream& bitmapFile)
{
	BitmapFileHeader fileHeader;
	bitmapFile.read(reinterpret_cast<char*>(&fileHeader.fileType), 2);
	bitmapFile.read(reinterpret_cast<char*>(&fileHeader.fileSize), 4);
	bitmapFile.read(reinterpret_cast<char*>(&fileHeader.reservedField1), 2);
	bitmapFile.read(reinterpret_cast<char*>(&fileHeader.reservedField2), 2);
	bitmapFile.read(reinterpret_cast<char*>(&fileHeader.offsetData), 4);
	return fileHeader;
}

BitmapInfoHeader HeadersLoader::loadBmpInfoHeader(ifstream& bitmapFile)
{
	BitmapInfoHeader infoHeader;
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
	return infoHeader;
}
