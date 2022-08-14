#pragma once
#include <fstream>
#include "Image.h"
class ImagesSaver
{
public:
	void saveImage(Image* image);
private:
	virtual void save(std::ofstream& imageFile, Image* image) = 0;
};

