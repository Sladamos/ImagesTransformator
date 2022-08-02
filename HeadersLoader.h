#pragma once
#include <string>
#include <fstream>
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
class HeadersLoader
{
public:
	static void loadHeaders(const std::string& bitmapName);
	static BitmapFileHeader getFileHeader();
	static BitmapInfoHeader getInfoHeader();
private:
	static void resetHeaders();
	static void loadBmpFileHeader(std::ifstream& bitmapFile);
	static void loadBmpInfoHeader(std::ifstream& bitmapFile);
	static BitmapFileHeader fileHeader;
	static BitmapInfoHeader infoHeader;
};

