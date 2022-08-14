#include "ImagesLoader.h"

void ImagesLoader::loadImageContent(Image* image)
{
	std::ifstream imageFile(std::string("./gfx/") + image->getName(), std::ios_base::binary);
	if (imageFile.is_open())
	{
		prepareAndLoadContent(imageFile, image);
		imageFile.close();
	}
}