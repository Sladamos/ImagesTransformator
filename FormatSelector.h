#pragma once
#include <vector>
#include <string>
class FormatSelector
{
public:
	static std::string selectNewFormat(const std::vector<std::string>& imagesFormats);
private:
	static void printSelector(const std::vector<std::string>& transformators);
	static std::string readFormatFromInput(const std::vector<std::string>& imagesFormats);
};

