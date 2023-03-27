#include "Bmp24Creator.h"

std::shared_ptr<Bmp24> Bmp24Creator::createImage()
{
    return std::shared_ptr<Bmp24>(new Bmp24());
}
