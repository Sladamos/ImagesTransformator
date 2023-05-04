#pragma once
#include <string>
#include "Image.h"
template<class T>
class ImagesCreator
{
public:
	ImagesCreator() = default;
	
	template<class W>
	ImagesCreator(const ImagesCreator<W> creator)
	{}

	std::shared_ptr<T> createImage()
	{
		return std::shared_ptr<T>(new T());
	}

	std::shared_ptr<T> createImage(const std::string& imageName)
	{
		return std::shared_ptr<T>(new T(imageName));
	}

};

