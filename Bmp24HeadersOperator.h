#pragma once
#include "BitmapHeadersOperator.h"
#include "Bmp24.h"
class Bmp24HeadersOperator : public BitmapHeadersOperator<Bmp24, Bmp24HeaderPtr>
{
public:
	bool areHeadersValidate(Bmp24* bitmap) override;
private:
	virtual void loadDIBHeader(std::ifstream& bitmapFile, Bmp24HeaderPtr bitmapHeader) override;
	virtual Bmp24HeaderPtr createHeaderPtr() override;
};

