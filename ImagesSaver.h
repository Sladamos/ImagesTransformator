#pragma once
#include <memory>
#include <string>
#include <fstream>
#include "Image.h"
template<class I, class H, class C>
class ImagesSaver
{
public:
	void saveImage(std::shared_ptr<I> image)
	{
		std::ofstream imageFile(DIRECTORY_PATH + image->getName(), std::ios::binary | std::ios::out | std::ios::trunc);
		if (imageFile.is_open())
		{
			writeImageHeader(imageFile, image->getImageHeader());
			writeImageContent(imageFile, image->getImageContent());
			imageFile.close();
		} 
	}
private:
	virtual void writeImageHeader(std::ofstream& imageFile, std::shared_ptr<H> imageHeader) = 0;
	virtual void writeImageContent(std::ofstream& imageFile, std::shared_ptr<C> imageContent) = 0;
	const std::string DIRECTORY_PATH = "./newGfx/";
};

