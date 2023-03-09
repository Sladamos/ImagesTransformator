#include "ImagesSaver.h"
using namespace std;
const string ImagesSaver::DIRECTORY_PATH = "./newGfx/";

void ImagesSaver::saveImage(Image* image)
{
	ofstream imageFile(DIRECTORY_PATH + image->getName(), ios::binary | ios::out | ios::trunc);
	if (imageFile.is_open())
	{
		writeImageHeader(imageFile, image->getImageHeader());
		writeImageContent(imageFile, image->getImageContent());
		imageFile.close();
	}
}