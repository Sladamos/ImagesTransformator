#pragma once
#include "HeadersOperator.h"
class Bmp24HeadersOperator : public HeadersOperator
{
public:
	bool areHeadersValidate(Image* image) override;
private:
	void load(std::ifstream& bitmapFile, Image* bitmap) override;
};

