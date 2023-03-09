#include "HeadersOperator.h"
using namespace std;

void HeadersOperator::loadHeaders(Image* image)
{
	ifstream imageFile(string("./gfx/") + image->getName(), ios_base::binary);
	if (imageFile.is_open())
	{
		image->setImageHeader(loadImageHeader(imageFile));
		imageFile.close();
	}
}


