#include <sstream>
#include "Bmp24FileHeader.h"

std::string Bmp24FileHeader::toString()
{
    std::stringstream output;
    output
        << "BMP24 FILE HEADER:\n"
        << "File type: " << fileType << "\n"
        << "File size: " << fileSize << "\n"
        << "First reserved field: " << reservedField1 << "\n"
        << "Second reserved field: " << reservedField2 << "\n"
        << "Offset data: " << offsetData << "\n"
        << "BMP24 INFO HEADER:\n"
        << "Header size: " << infoHeaderSize << "\n"
        << "Bitmap width: " << bitmapWidth << "\n"
        << "Bitmap height: " << bitmapHeight << "\n"
        << "Planes: " << planes << "\n"
        << "Bits per pixel: " << bitsPerPixel << "\n"
        << "Compression: " << compressionAlgorithm << "\n"
        << "Image size: " << imageSize << "\n"
        << "Horizontal resolution: " << horizontalResolution << "\n"
        << "Vertical resolution: " << verticalResolution << "\n"
        << "Colors used: " << colorsUsed << "\n"
        << "Important colors: " << colorsImportant << "\n";
    return output.str();
}