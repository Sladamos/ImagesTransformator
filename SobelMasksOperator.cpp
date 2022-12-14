#include "SobelMasksOperator.h"

SobelMasksOperator::SobelMasksOperator()
{
	initializeMasks();
}

void SobelMasksOperator::initializeMasks()
{
	int maskSize = 3;
	masks.push_back(Mask(maskSize,{
		1, 0, -1,
		2, 0, -2,
		1, 0, -1 }));

	masks.push_back(Mask(maskSize, {
		2, 1, 0,
		1, 0, -1,
		0, -1, -2 }));

	masks.push_back(Mask(maskSize, {
		1, 2, 1,
		0, 0, 0,
		-1, -2, -1 }));

	masks.push_back(Mask(maskSize, {
		0, 1, 2,
		-1, 0, 1,
		-2, -1, 0 }));
}