#pragma once
#include <memory>
class ImageContent
{
public:
	int getWidth() const;
	int getHeight() const;
protected:
	int width;
	int height;
};

typedef std::shared_ptr<ImageContent> ImageContentPtr;