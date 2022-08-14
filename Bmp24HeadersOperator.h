#pragma once
#include "HeadersOperator.h"
class Bmp24HeadersOperator : public HeadersOperator
{
public:
	bool areHeadersValidate(Bitmap* bitmap) override;
private:
	void load(std::ifstream& bitmapFile, Bitmap* bitmap) override;
};

