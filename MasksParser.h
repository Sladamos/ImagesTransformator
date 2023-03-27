#pragma once
#include <vector>
#include <string>
#include "Mask.h"
class MasksParser
{
public:
	virtual std::vector<Mask> loadMasks(const std::string& transformatorName) = 0;
};

