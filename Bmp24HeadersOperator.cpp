#include "Bmp24HeadersOperator.h"
using namespace std;

bool Bmp24HeadersOperator::areHeadersValidate(Bitmap* bitmap)
{
	BitmapFileHeader fileHeader = bitmap->getFileHeader();
	BitmapInfoHeader infoHeader = bitmap->getInfoHeader();
	return fileHeader.fileSize > 0 && fileHeader.fileType == 0x4D42 && infoHeader.planes == 1 && fileHeader.offsetData <= sizeof(fileHeader) + sizeof(infoHeader);
}

void Bmp24HeadersOperator::load(ifstream& bitmapFile, Bitmap* bitmap)
{
	bitmap->setFileHeader(loadBmpFileHeader(bitmapFile));
	bitmap->setInfoHeader(loadBmpInfoHeader(bitmapFile));
}