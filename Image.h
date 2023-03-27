#pragma once
#include <iostream>
#include <string>
#include "ImageHeader.h"
#include "ImageContent.h"
template<class H, class C>
class Image
{
public:
	Image(Image* source, const std::string& imageName);
	Image();
	virtual ~Image() = default;
	std::string getName() const;
	const H& getImageHeader() const;
	C& getImageContent() const;
	void setName(const std::string& name);
	void setImageHeader(std::shared_ptr<H> imageHeader);
	virtual std::string toString();
private:
	std::shared_ptr<H> imageHeader;
	std::shared_ptr<C> imageContent;
	std::string name;
};

