#include "ImagesLoader.h"

void ImagesLoader::loadImageContent(Bitmap* bitmap)
{
	std::ifstream bitmapFile(std::string("./gfx/") + bitmap->getName(), std::ios_base::binary);
	if (bitmapFile.is_open())
	{
		prepareAndLoadContent(bitmapFile, bitmap);
		bitmapFile.close();
	}
}