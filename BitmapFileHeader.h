#pragma once
#include <cstdint>
struct BitmapFileHeader
{
	uint16_t fileType;
	uint32_t fileSize;               
	uint16_t reservedField1{ 0 };              
	uint16_t reservedField2 { 0 };
	uint32_t offsetData;
};

