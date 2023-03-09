#pragma once
#include "MasksOperator.h"
class SobelMasksOperator : public MasksOperator
{
public:
	SobelMasksOperator();
private:
	std::string getName() override;
};

