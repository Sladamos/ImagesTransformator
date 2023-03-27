#include "ImagesSaver.h"
using namespace std;
template<class H, class C>
const string ImagesSaver<H, C>::DIRECTORY_PATH = "./newGfx/";

template<class H, class C>
void ImagesSaver<H, C>::saveImage(Image* image)
{
	ofstream imageFile(DIRECTORY_PATH + image->getName(), ios::binary | ios::out | ios::trunc);
	if (imageFile.is_open())
	{
		writeImageHeader(imageFile, image->getImageHeader());
		writeImageContent(imageFile, image->getImageContent());
		imageFile.close();
	}
}