#include "Mask.h"

Mask::Mask(int maskSize, std::vector<int> maskValues) : size(maskSize), maskValues(maskValues) {}

int Mask::operator[](int index) const
{
	return maskValues[index];
}

int Mask::getSize() const
{
	return size;
}