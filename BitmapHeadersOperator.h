#pragma once
#include "HeadersOperator.h"
#include "BitmapHeader.h"
template<class T, typename H>
class BitmapHeadersOperator : public HeadersOperator<T, H>
{
protected:
	std::shared_ptr<H> loadImageHeader(std::ifstream& bitmapFile) override
	{
		auto bitmapHeaderPtr = createHeaderPtr();
		auto& bitmapHeader = *bitmapHeaderPtr;
		bitmapFile.read(reinterpret_cast<char*>(&bitmapHeader.fileType), sizeof(bitmapHeader.fileType));
		bitmapFile.read(reinterpret_cast<char*>(&bitmapHeader.fileSize), sizeof(bitmapHeader.fileSize));
		bitmapFile.read(reinterpret_cast<char*>(&bitmapHeader.reservedField1), sizeof(bitmapHeader.reservedField1));
		bitmapFile.read(reinterpret_cast<char*>(&bitmapHeader.reservedField2), sizeof(bitmapHeader.reservedField2));
		bitmapFile.read(reinterpret_cast<char*>(&bitmapHeader.offsetData), sizeof(bitmapHeader.offsetData));
		loadDIBHeader(bitmapFile, bitmapHeaderPtr);
		return bitmapHeaderPtr;
	}
private:
	virtual std::shared_ptr<H> createHeaderPtr() = 0;
	virtual void loadDIBHeader(std::ifstream& bitmapFile, std::shared_ptr<H> bitmapHeader) = 0;
};

