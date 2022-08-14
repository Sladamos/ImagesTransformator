#pragma once
#include <string>
#include "Bmp24.h"
#include "MasksOperator.h"
class Transformator
{
public:
	Transformator(MasksOperator* masksOperator, Image*& sourceImage);
	virtual ~Transformator();
	Image* transformateImage(const std::string& outputName, const std::string& imageFormat);
protected:
	const MasksOperator* masksOperator;
	Image*& sourceImage;
	const std::vector<Mask> masks;
private:
	Bmp24* transformateBmp24(const std::string& outputName);
	virtual Pixel transformatePixel(const Pixel& sourcePixel);
};

