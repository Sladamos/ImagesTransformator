#pragma once
#include <string>
#include "Bitmap.h"
#include "MasksOperator.h"
class Transformator
{
public:
	Transformator(MasksOperator* masksOperator);
	virtual ~Transformator();
	Bitmap* transformateBitmap(const Bitmap& source, const std::string& outputName);
protected:
	MasksOperator* masksOperator;
private:
	virtual Pixel transformatePixel(const Bitmap& sourceBitmap, const Pixel& sourcePixel) = 0;
};

