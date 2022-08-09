#pragma once
#include "MasksOperator.h"
class SobelMasksOperator : public MasksOperator
{
public:
	SobelMasksOperator();
private:
	void initializeMasks() override;
};

