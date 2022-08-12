#include "SobelHeadersOperator.h"
using namespace std;

void SobelHeadersOperator::loadHeaders(Bitmap& bitmap)
{
	ifstream bitmapFile(string("./gfx/") + bitmap.getName(), ios_base::binary);
	if (bitmapFile.is_open())
	{
		bitmap.setFileHeader(loadBmpFileHeader(bitmapFile));
		bitmap.setInfoHeader(loadBmpInfoHeader(bitmapFile));
		bitmapFile.close();
	}
}

bool SobelHeadersOperator::areHeadersValidate(const Bitmap& bitmap)
{
	BitmapFileHeader fileHeader = bitmap.getFileHeader();
	BitmapInfoHeader infoHeader = bitmap.getInfoHeader();
	return fileHeader.fileSize > 0 && fileHeader.fileType == 0x4D42 && infoHeader.planes == 1 && fileHeader.offsetData <= sizeof(fileHeader) + sizeof(infoHeader);
}