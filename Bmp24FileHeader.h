#pragma once
#include <cstdint>
#include <string>
class Bmp24FileHeader
{
public:    
	std::string toString();

	uint16_t fileType;
	uint32_t fileSize;               
	uint16_t reservedField1;              
	uint16_t reservedField2;
	uint32_t offsetData;
};

