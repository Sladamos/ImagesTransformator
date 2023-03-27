#include "ImagesSaver.h"
using namespace std;
template<class I, class H, class C>
const string ImagesSaver<I, H, C>::DIRECTORY_PATH = "./newGfx/";

template<class I, class H, class C>
void ImagesSaver<I, H, C>::saveImage(I* image)
{
	ofstream imageFile(DIRECTORY_PATH + image->getName(), ios::binary | ios::out | ios::trunc);
	if (imageFile.is_open())
	{
		writeImageHeader(imageFile, image->getImageHeader());
		writeImageContent(imageFile, image->getImageContent());
		imageFile.close();
	}
}