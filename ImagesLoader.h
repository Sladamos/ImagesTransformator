#pragma once
#include <fstream>
#include "Image.h"
template<class T>
class ImagesLoader
{
public:
	void loadImageContent(T* image)	
	{
		std::ifstream imageFile(DIRECTORY_PATH + image->getName(), std::ios_base::binary);
		if (imageFile.is_open())
		{
			prepareAndLoadContent(imageFile, image);
			imageFile.close();
		}
	}
private:
	virtual void prepareAndLoadContent(std::ifstream& imageFile, T* image) = 0;
	const std::string DIRECTORY_PATH = "./gfx/";
};

