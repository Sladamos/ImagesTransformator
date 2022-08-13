#pragma once
#include <iostream>
#include <string>
class Image
{
public:
	virtual ~Image() = default;
	std::string getName() const;
	void setName(const std::string& name);
	friend std::ostream& operator<<(std::ostream& os, const Image& image);
protected:
	std::string name;
};

