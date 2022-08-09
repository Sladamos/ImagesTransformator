#pragma once
#include <cstdint>
#include <vector>
class Bitmap;
class Mask;
class Pixel
{
public:
	enum class Color
	{
		red,
		green,
		blue
	};

	int transformateColorByMask(const Bitmap& sourceBitmap, const Mask& mask, Pixel::Color color) const;

	uint8_t R{ 0 }, G{ 0 }, B{ 0 };
	int x, y;
private:
	Pixel createSourcePixel(const Bitmap& sourceBitmap, int row, int column) const;
	uint8_t getColorValue(Color color) const;
};

