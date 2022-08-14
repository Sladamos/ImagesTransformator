#include "ImagesSaver.h"
using namespace std;

void ImagesSaver::saveImage(Bitmap* bitmap)
{
	ofstream bitmapFile(string("./newGfx/") + bitmap->getName(), ios::binary | ios::out | ios::trunc);
	if (bitmapFile.is_open())
	{
		save(bitmapFile, bitmap);
		bitmapFile.close();
	}
}