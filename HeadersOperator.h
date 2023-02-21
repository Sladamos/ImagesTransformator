#pragma once
#include <string>
#include <fstream>
#include "Image.h"
class HeadersOperator
{
public:
	void loadHeaders(Image* image);
	virtual bool areHeadersValidate(Image* image) = 0;
private:
	virtual ImageHeaderPtr createHeaderPtr() = 0;
	virtual ImageHeaderPtr loadImageHeader(std::ifstream& imageFile) = 0;
};

