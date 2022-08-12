#pragma once
#include "HeadersOperator.h"
class SobelHeadersOperator : public HeadersOperator
{
public:
	bool areHeadersValidate(const Bitmap& bitmap) override;
};

