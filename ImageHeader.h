#pragma once
#include <string>
#include <memory>
class ImageHeader
{
public:
	virtual std::string toString() = 0;
};

typedef std::shared_ptr<ImageHeader> ImageHeaderPtr;

