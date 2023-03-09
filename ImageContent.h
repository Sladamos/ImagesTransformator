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
	virtual void createEmptyContent() = 0;
};

typedef std::shared_ptr<ImageContent> ImageContentPtr;