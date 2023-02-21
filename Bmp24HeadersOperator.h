#pragma once
#include "BitmapHeadersOperator.h"
#include "Bmp24.h"
class Bmp24HeadersOperator : public BitmapHeadersOperator
{
public:
	bool areHeadersValidate(Image* image) override;
private:
	virtual void loadDIBHeader(std::ifstream& bitmapFile, BitmapHeaderPtr bitmapHeader) override;
	virtual BitmapHeaderPtr createBitmapPtr() override;
};

