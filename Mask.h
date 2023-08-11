#pragma once
#include <vector>
class Mask
{
public:
	Mask() = default;
	Mask(std::pair<int, int> maskSize, std::vector<int> maskValues);
	int getNumberOfRows() const;
	int getNumberOfCols() const;
	int operator[](int index) const;
private:
	std::pair<int, int> size;
	std::vector<int> maskValues;
};

