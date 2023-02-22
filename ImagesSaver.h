#pragma once
#include <fstream>
#include "Image.h"
class ImagesSaver
{
public:
	void saveImage(Image* image);
private:
	virtual void writeImageHeader(std::ofstream& imageFile, const ImageHeader& imageHeader) = 0;
	virtual void writeImageContent(std::ofstream& imageFile, const ImageContent& imageContent) = 0;
};

