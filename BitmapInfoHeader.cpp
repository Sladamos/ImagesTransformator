#include "BitmapInfoHeader.h"

std::ostream& operator<<(std::ostream& os, const BitmapInfoHeader& infoHeader)
{
    os
        << "Header size: " << infoHeader.headerSize << "\n"
        << "Bitmap width: " << infoHeader.bitmapWidth << "\n"
        << "Bitmap height: " << infoHeader.bitmapHeight << "\n"
        << "Planes: " << infoHeader.planes << "\n"
        << "Bits per pixel: " << infoHeader.bitsPerPixel << "\n"
        << "Compression: " << infoHeader.compressionAlgorithm << "\n"
        << "Image size: " << infoHeader.imageSize << "\n"
        << "Horizontal resolution: " << infoHeader.horizontalResolution << "\n"
        << "Vertical resolution: " << infoHeader.verticalResolution << "\n"
        << "Colors used: " << infoHeader.colorsUsed << "\n"
        << "Important colors: " << infoHeader.colorsImportant << "\n";
    return os;
}