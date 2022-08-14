#pragma once
#include <fstream>
#include "Bitmap.h"
class ImagesSaver
{
public:
	void saveImage(Bitmap* bitmap);
private:
	virtual void save(std::ofstream& bitmapFile, Bitmap* bitmap) = 0;
};

