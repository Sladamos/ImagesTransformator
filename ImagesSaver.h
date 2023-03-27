#pragma once
#include <fstream>
#include "Image.h"
template<class I, class H, class C>
class ImagesSaver
{
public:
	void saveImage(I* image);
private:
	virtual void writeImageHeader(std::ofstream& imageFile, const H& imageHeader) = 0;
	virtual void writeImageContent(std::ofstream& imageFile, const C& imageContent) = 0;
	const static std::string DIRECTORY_PATH;
};

