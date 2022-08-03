#include "MasksOperator.h"

std::vector<std::vector<int>> MasksOperator::masks = std::vector<std::vector<int>>();

std::vector<int> MasksOperator::getMask(int maskNumber)
{
	std::vector<int> vec;
	if (maskNumber < masks.size())
		vec = masks[maskNumber];
	return vec;
}

void MasksOperator::initializeMasks()
{
	masks.push_back({
		1, 0, -1,
		2, 0, -2,
		1, 0, -1 });

	masks.push_back({
		1, 2, 1,
		0, 0, 0,
		-1, -2, -1 });
}