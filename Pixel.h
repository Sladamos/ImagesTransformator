#pragma once
#include <cstdint>
#include <vector>
class Pixel
{
public:
	void transformate(Pixel** sourcePixels, int maxWidth, int maxHeight);

	uint8_t R{ 0 }, G{ 0 }, B{ 0 };
	int x, y;
private:
	int transformateRedByMask(Pixel** sourcePixels, int maxWidth, int maxHeight, const std::vector<int>& mask);
	int transformateGreenByMask(Pixel** sourcePixels, int maxWidth, int maxHeight, const std::vector<int>& mask);
	int transformateBlueByMask(Pixel** sourcePixels, int maxWidth, int maxHeight, const std::vector<int>& mask);
};

