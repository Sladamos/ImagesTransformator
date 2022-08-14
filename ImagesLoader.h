#pragma once
#include <fstream>
#include "Image.h"
class ImagesLoader
{
public:
	void loadImageContent(Image* image);
private:
	virtual void prepareAndLoadContent(std::ifstream& imageFile, Image* image) = 0;
};

