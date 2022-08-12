#include "HeadersOperator.h"
using namespace std;

void HeadersOperator::loadHeaders(Bitmap& bitmap)
{
	ifstream bitmapFile(string("./gfx/") + bitmap.getName(), ios_base::binary);
	if (bitmapFile.is_open())
	{
		bitmap.setFileHeader(loadBmpFileHeader(bitmapFile));
		bitmap.setInfoHeader(loadBmpInfoHeader(bitmapFile));
		bitmapFile.close();
	}
}

BitmapFileHeader HeadersOperator::loadBmpFileHeader(ifstream& bitmapFile)
{
	BitmapFileHeader fileHeader;
	bitmapFile.read(reinterpret_cast<char*>(&fileHeader.fileType), sizeof(fileHeader.fileType));
	bitmapFile.read(reinterpret_cast<char*>(&fileHeader.fileSize), sizeof(fileHeader.fileSize));
	bitmapFile.read(reinterpret_cast<char*>(&fileHeader.reservedField1), sizeof(fileHeader.reservedField1));
	bitmapFile.read(reinterpret_cast<char*>(&fileHeader.reservedField2), sizeof(fileHeader.reservedField2));
	bitmapFile.read(reinterpret_cast<char*>(&fileHeader.offsetData), sizeof(fileHeader.offsetData));
	return fileHeader;
}

BitmapInfoHeader HeadersOperator::loadBmpInfoHeader(ifstream& bitmapFile)
{
	BitmapInfoHeader infoHeader;
	bitmapFile.read(reinterpret_cast<char*>(&infoHeader.headerSize), sizeof(infoHeader.headerSize));
	bitmapFile.read(reinterpret_cast<char*>(&infoHeader.bitmapWidth), sizeof(infoHeader.bitmapWidth));
	bitmapFile.read(reinterpret_cast<char*>(&infoHeader.bitmapHeight), sizeof(infoHeader.bitmapHeight));
	bitmapFile.read(reinterpret_cast<char*>(&infoHeader.planes), sizeof(infoHeader.planes));
	bitmapFile.read(reinterpret_cast<char*>(&infoHeader.bitsPerPixel), sizeof(infoHeader.bitsPerPixel));
	bitmapFile.read(reinterpret_cast<char*>(&infoHeader.compressionAlgorithm), sizeof(infoHeader.compressionAlgorithm));
	bitmapFile.read(reinterpret_cast<char*>(&infoHeader.imageSize), sizeof(infoHeader.imageSize));
	bitmapFile.read(reinterpret_cast<char*>(&infoHeader.horizontalResolution), sizeof(infoHeader.horizontalResolution));
	bitmapFile.read(reinterpret_cast<char*>(&infoHeader.verticalResolution), sizeof(infoHeader.verticalResolution));
	bitmapFile.read(reinterpret_cast<char*>(&infoHeader.colorsUsed), sizeof(infoHeader.colorsUsed));
	bitmapFile.read(reinterpret_cast<char*>(&infoHeader.colorsImportant), sizeof(infoHeader.colorsImportant));
	return infoHeader;
}

