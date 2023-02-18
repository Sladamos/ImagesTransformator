#pragma once
#include "MasksOperator.h"
class DampelMasksOperator : public MasksOperator
{
public:
	DampelMasksOperator();
private:
	void initializeMasks() override;
};

