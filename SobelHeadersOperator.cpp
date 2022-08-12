#include "SobelHeadersOperator.h"
using namespace std;

bool SobelHeadersOperator::areHeadersValidate(const Bitmap& bitmap)
{
	BitmapFileHeader fileHeader = bitmap.getFileHeader();
	BitmapInfoHeader infoHeader = bitmap.getInfoHeader();
	return fileHeader.fileSize > 0 && fileHeader.fileType == 0x4D42 && infoHeader.planes == 1 && fileHeader.offsetData <= sizeof(fileHeader) + sizeof(infoHeader);
}