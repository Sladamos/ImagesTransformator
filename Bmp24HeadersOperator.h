#pragma once
#include "HeadersOperator.h"
class Bmp24HeadersOperator : public HeadersOperator
{
public:
	bool areHeadersValidate(const Bitmap& bitmap) override;
};

