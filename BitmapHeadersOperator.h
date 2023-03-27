#pragma once
#include "HeadersOperator.h"
#include "BitmapHeader.h"
template<class T, typename P>
class BitmapHeadersOperator : public HeadersOperator<T, P>
{
protected:
	P loadImageHeader(std::ifstream& bitmapFile) override;
private:
	virtual P createHeaderPtr() = 0;
	virtual void loadDIBHeader(std::ifstream& bitmapFile, P bitmapHeader) = 0;
};

