#include "HeadersOperator.h"
using namespace std;

template <class T, typename P>
void HeadersOperator<T,P>::loadHeaders(T* image)
{
	ifstream imageFile(string("./gfx/") + image->getName(), ios_base::binary);
	if (imageFile.is_open())
	{
		image->setImageHeader(loadImageHeader(imageFile));
		imageFile.close();
	}
}


