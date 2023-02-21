#pragma once
#include "ImageHeader.h"
class BitmapHeader : public ImageHeader
{
public:
	uint16_t fileType;
	uint32_t fileSize;
	uint16_t reservedField1;
	uint16_t reservedField2;
	uint32_t offsetData;
};

typedef std::shared_ptr<BitmapHeader> BitmapHeaderPtr;

