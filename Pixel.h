#pragma once
#include <cstdint>
#include <vector>
class Bitmap;
class Pixel
{
public:
	void transformate(const Bitmap& sourceBitmap);

	enum class Color
	{
		red,
		green,
		blue
	};
	uint8_t R{ 0 }, G{ 0 }, B{ 0 };
	int x, y;
private:
	int transformateByMask(const Bitmap& sourceBitmap, const std::vector<int>& mask, Color color);
	int transformateRedByMask(Pixel** sourcePixels, int maxWidth, int maxHeight, const std::vector<int>& mask);
	int transformateGreenByMask(Pixel** sourcePixels, int maxWidth, int maxHeight, const std::vector<int>& mask);
	int transformateBlueByMask(Pixel** sourcePixels, int maxWidth, int maxHeight, const std::vector<int>& mask);
	uint8_t getColorValue(Color color);
	Pixel createSourcePixel(const Bitmap& sourceBitmap, int row, int column);
};

