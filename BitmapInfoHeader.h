#pragma once
#include <cstdint>
struct BitmapInfoHeader
{
	uint32_t headerSize;
	int32_t bitmapWidth;
	int32_t bitmapHeight;
	uint16_t planes{ 1 };
	uint16_t bitsPerPixel;
	uint32_t compressionAlgorithm;
	uint32_t imageSize;
	int32_t horizontalResolution;
	int32_t verticalResolution;
	uint32_t colorsUsed;
	uint32_t colorsImportant;
};

