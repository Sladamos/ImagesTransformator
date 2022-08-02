#include "BitmapFileHeader.h"

std::ostream& operator<<(std::ostream& os, const BitmapFileHeader& fileHeader)
{
    os
        << "File type: " << fileHeader.fileType << "\n"
        << "File size: " << fileHeader.fileSize << "\n"
        << "First reserved field: " << fileHeader.reservedField1 << "\n"
        << "Second reserver field: " << fileHeader.reservedField2 << "\n"
        << "Offset data: " << fileHeader.offsetData << "\n";
    return os;
}