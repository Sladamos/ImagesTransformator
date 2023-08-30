#pragma once
#include "MasksOperator.h"
class SobelMasksOperator : public MasksOperator
{
public:
	SobelMasksOperator(const std::string& masksPath);
private:
	std::string getName() override;
};

