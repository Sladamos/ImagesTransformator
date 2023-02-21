#include "Bmp24HeadersOperator.h"
using namespace std;

bool Bmp24HeadersOperator::areHeadersValidate(Image* image)
{
	Bmp24* bitmap = reinterpret_cast<Bmp24*>(image);
	Bmp24Header bitmapHeader = dynamic_cast<const Bmp24Header&>(bitmap->getImageHeader());
	return bitmapHeader.fileSize > 0 && bitmapHeader.fileType == 0x4D42 && bitmapHeader.planes == 1 && bitmapHeader.offsetData <= sizeof(bitmapHeader);
}

void Bmp24HeadersOperator::loadDIBHeader(std::ifstream& bitmapFile, BitmapHeaderPtr bitmapHeader)
{
	Bmp24Header bmp24Header = dynamic_cast<Bmp24Header&>(*bitmapHeader);
	bitmapFile.read(reinterpret_cast<char*>(&bmp24Header.infoHeaderSize), sizeof(bmp24Header.infoHeaderSize));
	bitmapFile.read(reinterpret_cast<char*>(&bmp24Header.bitmapWidth), sizeof(bmp24Header.bitmapWidth));
	bitmapFile.read(reinterpret_cast<char*>(&bmp24Header.bitmapHeight), sizeof(bmp24Header.bitmapHeight));
	bitmapFile.read(reinterpret_cast<char*>(&bmp24Header.planes), sizeof(bmp24Header.planes));
	bitmapFile.read(reinterpret_cast<char*>(&bmp24Header.bitsPerPixel), sizeof(bmp24Header.bitsPerPixel));
	bitmapFile.read(reinterpret_cast<char*>(&bmp24Header.compressionAlgorithm), sizeof(bmp24Header.compressionAlgorithm));
	bitmapFile.read(reinterpret_cast<char*>(&bmp24Header.imageSize), sizeof(bmp24Header.imageSize));
	bitmapFile.read(reinterpret_cast<char*>(&bmp24Header.horizontalResolution), sizeof(bmp24Header.horizontalResolution));
	bitmapFile.read(reinterpret_cast<char*>(&bmp24Header.verticalResolution), sizeof(bmp24Header.verticalResolution));
	bitmapFile.read(reinterpret_cast<char*>(&bmp24Header.colorsUsed), sizeof(bmp24Header.colorsUsed));
	bitmapFile.read(reinterpret_cast<char*>(&bmp24Header.colorsImportant), sizeof(bmp24Header.colorsImportant));
}

BitmapHeaderPtr Bmp24HeadersOperator::createBitmapPtr()
{
	return Bmp24HeaderPtr(new Bmp24Header());
}