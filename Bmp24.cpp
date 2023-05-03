#include "Bmp24.h"

Bmp24::Bmp24() : Image()
{

}

void Bmp24::setName(const std::string& name)
{
	Image::setName(name + ".bmp");
}

Bmp24::Bmp24(const std::string& bitmapName) : Image(bitmapName)
{
}
