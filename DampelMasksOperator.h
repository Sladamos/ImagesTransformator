#pragma once
#include "MasksOperator.h"
class DampelMasksOperator : public MasksOperator
{
public:
	DampelMasksOperator(const std::string& masksPath);
private:
	std::string getName() override;
};

