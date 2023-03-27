#pragma once
#include "HeadersOperator.h"
#include "BitmapHeader.h"
template<class T>
class BitmapHeadersOperator : public HeadersOperator<T, BitmapHeaderPtr>
{
protected:
	BitmapHeaderPtr loadImageHeader(std::ifstream& bitmapFile) override;
private:
	virtual BitmapHeaderPtr createHeaderPtr() = 0;
	virtual void loadDIBHeader(std::ifstream& bitmapFile, BitmapHeaderPtr bitmapHeader) = 0;
};

