#pragma once
#include <iostream>
#include <string>
class Image
{
public:
	virtual ~Image() = default;
	std::string getName() const;
	void setName(const std::string& name);
protected:
	std::string name;
};

