#pragma once
#include <vector>
#include "Mask.h"
class MasksOperator
{
public:
	int getNumberOfMasks();
	Mask getMask(int maskNumber);
	const std::vector<Mask>& getMasks();
protected:
	std::vector<Mask> masks;
private:
	virtual void initializeMasks() = 0;
};

