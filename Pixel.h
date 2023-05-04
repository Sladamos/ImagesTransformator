#pragma once
#include <cstdint>
#include <vector>
#include <memory>
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

typedef std::shared_ptr<Pixel[]> PixelsRow;
typedef std::shared_ptr<std::shared_ptr<Pixel[]>[]> Pixels;

