#pragma once
#include <map>
#include <string>
#include "Option.h"
class OptionsCreator
{
	virtual std::map<std::string, std::map<std::string, std::shared_ptr<Option>>> createOptions() = 0;
};
