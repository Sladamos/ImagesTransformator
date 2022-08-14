#pragma once
#include <string>
#include "Bitmap.h"
#include "MasksOperator.h"
class Transformator
{
public:
	Transformator(MasksOperator* masksOperator, Bitmap*& sourceBitmap);
	virtual ~Transformator();
	Bitmap* transformateImage(const std::string& outputName);
protected:
	const MasksOperator* masksOperator;
	Bitmap*& sourceBitmap;
	const std::vector<Mask> masks;
private:
	virtual Pixel transformatePixel(const Pixel& sourcePixel) = 0;
};

