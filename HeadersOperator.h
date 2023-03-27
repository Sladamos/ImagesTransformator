#pragma once
#include <string>
#include <fstream>
#include "Image.h"
template <class T, typename P>
class HeadersOperator
{
public:
	void loadHeaders(T* image);
	virtual bool areHeadersValidate(T* image) = 0;
private:
	virtual P createHeaderPtr() = 0;
	virtual P loadImageHeader(std::ifstream& imageFile) = 0;
};

