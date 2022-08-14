#include <sstream>
#include "Bmp24InfoHeader.h"

std::string Bmp24InfoHeader::toString()
{
    std::stringstream output;
    output
        << "Header size: " << headerSize << "\n"
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