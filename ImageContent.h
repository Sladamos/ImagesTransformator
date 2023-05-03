#pragma once
#include <memory>
class ImageContent
{
public:
	int getWidth() const;
	int getHeight() const;

	void setWidth(int width);
	void setHeight(int height);
protected:
	int width;
	int height;
};

typedef std::shared_ptr<ImageContent> ImageContentPtr;