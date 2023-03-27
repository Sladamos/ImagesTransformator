#pragma once
#include "BitmapHeadersOperator.h"
#include "Bmp24.h"
class Bmp24HeadersOperator : public BitmapHeadersOperator<Bmp24>
{
public:
	bool areHeadersValidate(Bmp24* bitmap) override;
private:
	virtual void loadDIBHeader(std::ifstream& bitmapFile, BitmapHeaderPtr bitmapHeader) override;
	virtual BitmapHeaderPtr createHeaderPtr() override;
};

