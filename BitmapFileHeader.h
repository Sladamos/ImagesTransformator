#pragma once
#include <cstdint>
#include <iostream>
class BitmapFileHeader
{
public:    
	friend std::ostream& operator<<(std::ostream& os, const BitmapFileHeader& fileHeader);
	uint16_t fileType;
	uint32_t fileSize;               
	uint16_t reservedField1;              
	uint16_t reservedField2;
	uint32_t offsetData;
};

