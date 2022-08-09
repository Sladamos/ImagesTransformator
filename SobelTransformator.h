#pragma once
#include "Transformator.h"
class SobelTransformator : public Transformator
{
public:
	SobelTransformator();
private:
	Pixel transformatePixel(const Bitmap& sourceBitmap, const Pixel& sourcePixel) override;
};

