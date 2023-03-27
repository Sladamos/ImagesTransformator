#include "ImagesLoader.h"
template<class T>
const std::string ImagesLoader<T>::DIRECTORY_PATH = "./gfx/";

template<class T>
void ImagesLoader<T>::loadImageContent(T* image)
{
	std::ifstream imageFile(DIRECTORY_PATH + image->getName(), std::ios_base::binary);
	if (imageFile.is_open())
	{
		prepareAndLoadContent(imageFile, image);
		imageFile.close();
	}
}
