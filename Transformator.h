#pragma once
#include <string>
#include <memory>
#include "Bmp24.h"
#include "MasksOperator.h"
template<class T>
class Transformator
{
public:
	Transformator(const std::vector<Mask>& masks) : masks(masks)
	{
	}

	virtual std::shared_ptr<T> transformateImage(std::shared_ptr<T> source) = 0;
protected:
	const std::vector<Mask> masks;
};
