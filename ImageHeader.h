#pragma once
#include <string>
#include <memory>
class ImageHeader
{
public:
	ImageHeader() = default;
	ImageHeader(const ImageHeader&) = default;
	virtual std::string toString() = 0;
};

typedef std::shared_ptr<ImageHeader> ImageHeaderPtr;

