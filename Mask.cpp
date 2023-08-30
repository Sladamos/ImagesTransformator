#include "Mask.h"

Mask::Mask(std::pair<int, int> maskSize, std::vector<int> maskValues) : size(maskSize), maskValues(maskValues) {}

int Mask::operator[](int index) const
{
	return maskValues[index];
}

int Mask::getNumberOfRows() const
{
	return size.second;
}

int Mask::getNumberOfCols() const
{
	return size.first;
}