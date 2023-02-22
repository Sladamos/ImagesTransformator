#include "ImagesSaver.h"
using namespace std;

void ImagesSaver::saveImage(Image* image)
{
	ofstream imageFile(string("./newGfx/") + image->getName(), ios::binary | ios::out | ios::trunc);
	if (imageFile.is_open())
	{
		writeImageHeader(imageFile, image->getImageHeader());
		writeImageContent(imageFile, image->getImageContent());
		imageFile.close();
	}
}