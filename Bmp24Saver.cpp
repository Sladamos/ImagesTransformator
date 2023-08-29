#include "Bmp24Saver.h"
using namespace std;

Bmp24Saver::Bmp24Saver(const std::string& directory_path) : ImagesSaver<Bmp24, Bmp24Header, Bmp24Content>(directory_path)
{
}

void Bmp24Saver::writeImageHeader(ofstream& bitmapFile, std::shared_ptr<Bmp24Header> imageHeader)
{
	Bmp24Header& bitmapHeader = *imageHeader;
	bitmapFile.write(reinterpret_cast<const char*>(&bitmapHeader.fileType), sizeof(bitmapHeader.fileType));
	bitmapFile.write(reinterpret_cast<const char*>(&bitmapHeader.fileSize), sizeof(bitmapHeader.fileSize));
	bitmapFile.write(reinterpret_cast<const char*>(&bitmapHeader.reservedField1), sizeof(bitmapHeader.reservedField1));
	bitmapFile.write(reinterpret_cast<const char*>(&bitmapHeader.reservedField2), sizeof(bitmapHeader.reservedField2));
	bitmapFile.write(reinterpret_cast<const char*>(&bitmapHeader.offsetData), sizeof(bitmapHeader.offsetData));
	bitmapFile.write(reinterpret_cast<const char*>(&bitmapHeader.infoHeaderSize), sizeof(bitmapHeader.infoHeaderSize));
	bitmapFile.write(reinterpret_cast<const char*>(&bitmapHeader.bitmapWidth), sizeof(bitmapHeader.bitmapWidth));
	bitmapFile.write(reinterpret_cast<const char*>(&bitmapHeader.bitmapHeight), sizeof(bitmapHeader.bitmapHeight));
	bitmapFile.write(reinterpret_cast<const char*>(&bitmapHeader.planes), sizeof(bitmapHeader.planes));
	bitmapFile.write(reinterpret_cast<const char*>(&bitmapHeader.bitsPerPixel), sizeof(bitmapHeader.bitsPerPixel));
	bitmapFile.write(reinterpret_cast<const char*>(&bitmapHeader.compressionAlgorithm), sizeof(bitmapHeader.compressionAlgorithm));
	bitmapFile.write(reinterpret_cast<const char*>(&bitmapHeader.imageSize), sizeof(bitmapHeader.imageSize));
	bitmapFile.write(reinterpret_cast<const char*>(&bitmapHeader.horizontalResolution), sizeof(bitmapHeader.horizontalResolution));
	bitmapFile.write(reinterpret_cast<const char*>(&bitmapHeader.verticalResolution), sizeof(bitmapHeader.verticalResolution));
	bitmapFile.write(reinterpret_cast<const char*>(&bitmapHeader.colorsUsed), sizeof(bitmapHeader.colorsUsed));
	bitmapFile.write(reinterpret_cast<const char*>(&bitmapHeader.colorsImportant), sizeof(bitmapHeader.colorsImportant));
}

void Bmp24Saver::writeImageContent(ofstream& bitmapFile, std::shared_ptr<Bmp24Content> imageContent)
{
	Bmp24Content& bitmapContent = *imageContent;
	string zeroBytes(bitmapContent.getNumberOfZeroBytes(), '0');
	int bitmapWidth = bitmapContent.getWidth();
	int bitmapHeight = bitmapContent.getHeight();

	for (int y = 0; y < bitmapHeight; y++)
	{
		for (int x = 0; x < bitmapWidth; x++)
			writePixel(bitmapFile, bitmapContent(y,x));
		bitmapFile.write(zeroBytes.c_str(), bitmapContent.getNumberOfZeroBytes());
	}
}

void Bmp24Saver::writePixel(std::ofstream& bitmapFile, const Pixel& pixel)
{
	bitmapFile.write(reinterpret_cast<const char*>(&pixel.B), sizeof(pixel.B));
	bitmapFile.write(reinterpret_cast<const char*>(&pixel.G), sizeof(pixel.G));
	bitmapFile.write(reinterpret_cast<const char*>(&pixel.R), sizeof(pixel.R));
}
