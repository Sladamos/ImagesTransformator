#pragma once
#include <string>
#include <memory>
class ImageHeader
{
public:
	virtual std::string toString() = 0;
};

typedef std::unique_ptr<ImageHeader> ImageHeaderPtr;

