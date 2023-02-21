#pragma once
#include <cstdint>
#include <string>
#include "ImageHeader.h"
class Bmp24FileHeader : public ImageHeader
{
public:    
	virtual std::string toString() override;

	uint16_t fileType;
	uint32_t fileSize;               
	uint16_t reservedField1;              
	uint16_t reservedField2;
	uint32_t offsetData;

	uint32_t infoHeaderSize;
	int32_t bitmapWidth;
	int32_t bitmapHeight;
	uint16_t planes;
	uint16_t bitsPerPixel;
	uint32_t compressionAlgorithm;
	uint32_t imageSize;
	int32_t horizontalResolution;
	int32_t verticalResolution;
	uint32_t colorsUsed;
	uint32_t colorsImportant;
};

