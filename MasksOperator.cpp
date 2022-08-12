#include "MasksOperator.h"

int MasksOperator::getNumberOfMasks()
{
	return masks.size();
}

const std::vector<Mask>& MasksOperator::getMasks()
{
	return masks;
}

Mask MasksOperator::getMask(int maskNumber)
{
	Mask mask;
	if (maskNumber < masks.size())
		mask = masks[maskNumber];
	return mask;
}
