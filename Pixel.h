#pragma once
#include <cstdint>
#include <vector>
class Pixel
{
public:
	enum class Color
	{
		red,
		green,
		blue
	};

	uint8_t getColorValue(Color color) const;
	uint8_t R{ 0 }, G{ 0 }, B{ 0 };
	int x, y;
};

