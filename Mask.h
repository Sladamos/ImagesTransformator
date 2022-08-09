#pragma once
#include <vector>
class Mask
{
public:
	Mask() = default;
	Mask(int maskSize, std::vector<int> maskValues);
	int getSize() const;
	int operator[](int index) const;
private:
	int size;
	std::vector<int> maskValues;
};

