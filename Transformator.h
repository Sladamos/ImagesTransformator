#pragma once
#include <string>
#include "Bitmap.h"
#include "MasksOperator.h"
class Transformator
{
public:
	Transformator(MasksOperator* masksOperator, const Bitmap& sourceBitmap);
	virtual ~Transformator();
	Bitmap* transformateBitmap(const std::string& outputName);
protected:
	const MasksOperator* masksOperator;
	const Bitmap& sourceBitmap;
	const std::vector<Mask> masks;
private:
	virtual Pixel transformatePixel(const Pixel& sourcePixel) = 0;
};

