#pragma once
#include <memory>
#include <fstream>
#include "Image.h"
template<class T>
class ImagesLoader
{
public:
	ImagesLoader(const std::string& directory_path) : directory_path(directory_path)
	{
	}

	void loadImageContent(std::shared_ptr<T> image)	
	{
		std::ifstream imageFile(directory_path + image->getName(), std::ios_base::binary);
		if (imageFile.is_open())
		{
			prepareAndLoadContent(imageFile, image);
			imageFile.close();
		}
	}
private:
	virtual void prepareAndLoadContent(std::ifstream& imageFile, std::shared_ptr<T> image) = 0;
	const std::string directory_path;
};

