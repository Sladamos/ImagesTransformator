#include "BitmapHeadersOperator.h"

ImageHeaderPtr BitmapHeadersOperator::loadImageHeader(std::ifstream& bitmapFile)
{
	BitmapHeaderPtr bitmapHeader = createBitmapPtr();
	bitmapFile.read(reinterpret_cast<char*>(bitmapHeader->fileType), sizeof(bitmapHeader->fileType));
	bitmapFile.read(reinterpret_cast<char*>(bitmapHeader->fileSize), sizeof(bitmapHeader->fileSize));
	bitmapFile.read(reinterpret_cast<char*>(bitmapHeader->reservedField1), sizeof(bitmapHeader->reservedField1));
	bitmapFile.read(reinterpret_cast<char*>(bitmapHeader->reservedField2), sizeof(bitmapHeader->reservedField2));
	bitmapFile.read(reinterpret_cast<char*>(bitmapHeader->offsetData), sizeof(bitmapHeader->offsetData));
	loadDIBHeader(bitmapFile, bitmapHeader);
	return bitmapHeader;
}