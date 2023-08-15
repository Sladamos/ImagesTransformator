#pragma once
#include "Transformator.h"
#include "ThreadPool.h"
class Bmp24Transformator : public Transformator<Bmp24>
{
public:
	Bmp24Transformator(const std::vector<Mask>& masks);
	virtual std::shared_ptr<Bmp24> transformateImage(std::shared_ptr<Bmp24> source) override;
protected:
	virtual Pixel transformatePixel(const Pixel& sourcePixel);
	
	std::shared_ptr<Bmp24> currentSource;
private:
	std::shared_ptr<Bmp24> transformSource();
	void transformSector(Pixels outputPixels, int xStart, int yStart, int xEnd, int yEnd);
	uint8_t transformatePixelColor(const Pixel& sourcePixel, Pixel::Color color);
	Pixel getNeighbourPixel(int row, int column);
	int transformateColorByMask(const Pixel& sourcePixel, const Mask& mask, Pixel::Color color);

	const int maxSectorWidth;
	const int maxSectorHeight;
	ThreadPool threadPool;
};

