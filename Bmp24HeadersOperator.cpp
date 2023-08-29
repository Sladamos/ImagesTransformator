#include "Bmp24HeadersOperator.h"
using namespace std;

Bmp24HeadersOperator::Bmp24HeadersOperator(const std::string& directory_path) : BitmapHeadersOperator(directory_path)
{
}

bool Bmp24HeadersOperator::areHeadersValidate(shared_ptr<Bmp24> bitmap)
{
	auto bitmapHeader = bitmap->getImageHeader();
	return bitmapHeader != nullptr && bitmapHeader->fileSize > 0 && bitmapHeader->fileType == 0x4D42 && bitmapHeader->planes == 1 && bitmapHeader->offsetData <= sizeof(*bitmapHeader);
}

void Bmp24HeadersOperator::loadDIBHeader(std::ifstream& bitmapFile, std::shared_ptr<Bmp24Header> bitmapHeader)
{
	auto& bmp24Header = *bitmapHeader;
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

Bmp24HeaderPtr Bmp24HeadersOperator::createHeaderPtr()
{
	return Bmp24HeaderPtr(new Bmp24Header());
}