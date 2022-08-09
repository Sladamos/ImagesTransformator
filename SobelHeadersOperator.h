#pragma once
#include "HeadersOperator.h"
class SobelHeadersOperator : public HeadersOperator
{
public:
	void loadHeaders(Bitmap& bitmap) override;
	bool areHeadersValidate(const Bitmap& bitmap) override;
};

