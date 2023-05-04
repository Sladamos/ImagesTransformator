#pragma once
#include <cstdint>
#include <string>
#include "BitmapHeader.h"
class Bmp24Header : public BitmapHeader
{
public:    
	virtual std::string toString() override;

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

typedef std::shared_ptr<Bmp24Header> Bmp24HeaderPtr;