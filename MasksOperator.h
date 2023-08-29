#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Mask.h"
#include "RapidXMLMasksParser.h"
class MasksOperator
{
public:
	MasksOperator(const std::string& masksPath);
	std::vector<Mask> getMasks();	
	virtual std::string getName() = 0;
private:
	std::string masksPath;
};

