#include "ImagesLoader.h"
const std::string ImagesLoader::DIRECTORY_PATH = "./gfx/";

void ImagesLoader::loadImageContent(Image* image)
{
	std::ifstream imageFile(DIRECTORY_PATH + image->getName(), std::ios_base::binary);
	if (imageFile.is_open())
	{
		prepareAndLoadContent(imageFile, image);
		imageFile.close();
	}
}