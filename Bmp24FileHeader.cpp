#include <sstream>
#include "Bmp24FileHeader.h"

std::string Bmp24FileHeader::toString()
{
    std::stringstream output;
    output
        << "File type: " << fileType << "\n"
        << "File size: " << fileSize << "\n"
        << "First reserved field: " << reservedField1 << "\n"
        << "Second reserved field: " << reservedField2 << "\n"
        << "Offset data: " << offsetData << "\n";
    return output.str();
}