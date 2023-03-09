#pragma once
#include "HeadersOperator.h"
#include "BitmapHeader.h"
class BitmapHeadersOperator : public HeadersOperator
{
protected:
	ImageHeaderPtr loadImageHeader(std::ifstream& bitmapFile) override;
private:
	virtual ImageHeaderPtr createHeaderPtr() { return createBitmapPtr(); };
	virtual BitmapHeaderPtr createBitmapPtr() = 0;
	virtual void loadDIBHeader(std::ifstream& bitmapFile, BitmapHeaderPtr bitmapHeader) = 0;
};

