#include "SobelMasksOperator.h"

SobelMasksOperator::SobelMasksOperator(const std::string& masksPath) : MasksOperator(masksPath)
{
}

std::string SobelMasksOperator::getName()
{
	return "Sobel";
}