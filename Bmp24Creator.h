#pragma once
#include "ImagesCreator.h"
#include "Bmp24.h"
class Bmp24Creator : public ImagesCreator<Bmp24>
{
	// Odziedziczono za po�rednictwem elementu ImagesCreator
	virtual std::shared_ptr<Bmp24> createImage() override;
};

