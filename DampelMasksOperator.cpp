#include "DampelMasksOperator.h"

DampelMasksOperator::DampelMasksOperator(const std::string& masksPath) : MasksOperator(masksPath)
{
}

std::string DampelMasksOperator::getName()
{
	return "Dampel";
}