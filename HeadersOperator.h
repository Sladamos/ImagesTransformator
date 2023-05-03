#pragma once
#include <string>
#include <memory>
#include <fstream>
#include "Image.h"
template <class T, typename H>
class HeadersOperator
{
public:
	HeadersOperator() = default;

	template <class W, class Z>
	HeadersOperator(const HeadersOperator<W, Z>&)
	{}


	void loadHeaders(std::shared_ptr<T> image)
	{
		std::ifstream imageFile(std::string("./gfx/") + image->getName(), std::ios_base::binary);
		if (imageFile.is_open())
		{
			image->setImageHeader(loadImageHeader(imageFile));
			imageFile.close();
		}
	}

	virtual bool areHeadersValidate(std::shared_ptr<T> image) = 0;
private:
	virtual std::shared_ptr<H> createHeaderPtr() = 0;
	virtual std::shared_ptr<H> loadImageHeader(std::ifstream& imageFile) = 0;
};

