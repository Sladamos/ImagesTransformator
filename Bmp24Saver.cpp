#include "Bmp24Saver.h"
using namespace std;

void Bmp24Saver::save(ofstream& bitmapFile, Image* image)
{
	Bmp24* bitmap = reinterpret_cast<Bmp24*>(image);
	writeFileHeader(bitmapFile, bitmap->getFileHeader());
	writeInfoHeader(bitmapFile, bitmap->getInfoHeader());
	writePixels(bitmapFile, bitmap);
}

void Bmp24Saver::writeFileHeader(ofstream& bitmapFile, const Bmp24FileHeader& fileHeader)
{
	bitmapFile.write(reinterpret_cast<const char*>(&fileHeader.fileType), sizeof(fileHeader.fileType));
	bitmapFile.write(reinterpret_cast<const char*>(&fileHeader.fileSize), sizeof(fileHeader.fileSize));
	bitmapFile.write(reinterpret_cast<const char*>(&fileHeader.reservedField1), sizeof(fileHeader.reservedField1));
	bitmapFile.write(reinterpret_cast<const char*>(&fileHeader.reservedField2), sizeof(fileHeader.reservedField2));
	bitmapFile.write(reinterpret_cast<const char*>(&fileHeader.offsetData), sizeof(fileHeader.offsetData));
}

void Bmp24Saver::writeInfoHeader(ofstream& bitmapFile, const Bmp24InfoHeader& infoHeader)
{
	bitmapFile.write(reinterpret_cast<const char*>(&infoHeader.headerSize), sizeof(infoHeader.headerSize));
	bitmapFile.write(reinterpret_cast<const char*>(&infoHeader.bitmapWidth), sizeof(infoHeader.bitmapWidth));
	bitmapFile.write(reinterpret_cast<const char*>(&infoHeader.bitmapHeight), sizeof(infoHeader.bitmapHeight));
	bitmapFile.write(reinterpret_cast<const char*>(&infoHeader.planes), sizeof(infoHeader.planes));
	bitmapFile.write(reinterpret_cast<const char*>(&infoHeader.bitsPerPixel), sizeof(infoHeader.bitsPerPixel));
	bitmapFile.write(reinterpret_cast<const char*>(&infoHeader.compressionAlgorithm), sizeof(infoHeader.compressionAlgorithm));
	bitmapFile.write(reinterpret_cast<const char*>(&infoHeader.imageSize), sizeof(infoHeader.imageSize));
	bitmapFile.write(reinterpret_cast<const char*>(&infoHeader.horizontalResolution), sizeof(infoHeader.horizontalResolution));
	bitmapFile.write(reinterpret_cast<const char*>(&infoHeader.verticalResolution), sizeof(infoHeader.verticalResolution));
	bitmapFile.write(reinterpret_cast<const char*>(&infoHeader.colorsUsed), sizeof(infoHeader.colorsUsed));
	bitmapFile.write(reinterpret_cast<const char*>(&infoHeader.colorsImportant), sizeof(infoHeader.colorsImportant));
}

void Bmp24Saver::writePixels(std::ofstream& bitmapFile, Bmp24* bitmap)
{
	string zeroBytes(bitmap->getNumberOfZeroBytes(), '0');
	Pixel** pixels = bitmap->getPixels();
	int bitmapWidth = bitmap->getInfoHeader().bitmapWidth, bitmapHeight = bitmap->getInfoHeader().bitmapHeight;
	for (int y = 0; y < bitmapHeight; y++)
	{
		for (int x = 0; x < bitmapWidth; x++)
			writePixel(bitmapFile, pixels[y][x]);
		bitmapFile.write(zeroBytes.c_str(), bitmap->getNumberOfZeroBytes());
	}
}

void Bmp24Saver::writePixel(std::ofstream& bitmapFile, const Pixel& pixel)
{
	bitmapFile.write(reinterpret_cast<const char*>(&pixel.B), sizeof(pixel.B));
	bitmapFile.write(reinterpret_cast<const char*>(&pixel.G), sizeof(pixel.G));
	bitmapFile.write(reinterpret_cast<const char*>(&pixel.R), sizeof(pixel.R));
}
