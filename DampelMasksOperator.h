#pragma once
#include "MasksOperator.h"
class DampelMasksOperator : public MasksOperator
{
public:
	DampelMasksOperator();
private:
	std::string getName() override;
};

