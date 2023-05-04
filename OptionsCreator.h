#pragma once
#include <map>
#include <string>
template <class T>
class OptionsCreator
{
	virtual std::map<std::string, std::map<std::string, std::shared_ptr<Option>>> createOptions(T* instance) = 0;
};
