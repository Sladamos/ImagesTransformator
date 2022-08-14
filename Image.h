#pragma once
#include <iostream>
#include <string>
class Image
{
public:
	virtual ~Image() = default;
	std::string getName() const;
	void setName(const std::string& name);
	virtual void clear();
	virtual std::string toString() = 0;
protected:
	std::string name;
};

