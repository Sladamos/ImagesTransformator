#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Mask.h"
#include "RapidXMLMasksParser.h"
class MasksOperator
{
public:
	int getNumberOfMasks();
	Mask getMask(int maskNumber);
	const std::vector<Mask>& getMasks();
protected:
	std::vector<Mask> masks;
private:
	void initializeMasks();
	virtual std::string getName() = 0;
};

