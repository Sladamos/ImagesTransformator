#pragma once
#include "ImagesCreator.h"
#include "Bmp24.h"
class Bmp24Creator : public ImagesCreator<Bmp24>
{
public:
	virtual std::shared_ptr<Bmp24> createImage() override;
};

