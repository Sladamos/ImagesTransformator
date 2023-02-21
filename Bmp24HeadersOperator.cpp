#include "Bmp24HeadersOperator.h"
using namespace std;

bool Bmp24HeadersOperator::areHeadersValidate(Image* image)
{
	Bmp24* bitmap = reinterpret_cast<Bmp24*>(image);
	Bmp24Header fileHeader = bitmap->getFileHeader();
	Bmp24InfoHeader infoHeader = bitmap->getInfoHeader();
	return fileHeader.fileSize > 0 && fileHeader.fileType == 0x4D42 && infoHeader.planes == 1 && fileHeader.offsetData <= sizeof(fileHeader) + sizeof(infoHeader);
}

void Bmp24HeadersOperator::load(ifstream& bitmapFile, Image* image)
{
	Bmp24* bitmap = reinterpret_cast<Bmp24*>(image);
	bitmap->setFileHeader(loadBmpFileHeader(bitmapFile));
	bitmap->setInfoHeader(loadBmpInfoHeader(bitmapFile));
}