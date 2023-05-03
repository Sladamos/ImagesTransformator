#pragma once
#include <string>
#include "Image.h"
#include "Pixel.h"
#include "Bmp24Header.h"
#include "Bmp24Content.h"
class Bmp24 : public Image<Bmp24Header, Bmp24Content>
{
public:
	Bmp24();
	virtual void setName(const std::string& name) override;
	Bmp24(const std::string& bitmapName);
};

