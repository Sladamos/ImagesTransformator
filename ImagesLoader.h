#pragma once
#include <fstream>
#include "Bitmap.h"
class ImagesLoader
{
public:
	void loadImageContent(Bitmap* bitmap);
private:
	virtual void prepareAndLoadContent(std::ifstream& bitmapFile, Bitmap* bitmap) = 0;
};

