#include "Option.h"

Option::Option(const std::string& name) : name(name)
{
}

const std::string& Option::getName()
{
	return name;
}
