#pragma once
#include <vector>
#include <string>
class FormatSelector
{
public:
	FormatSelector(const std::vector<std::string>& imagesFormats);
	std::string selectNewFormat();
protected:
	std::vector<std::string> imagesFormats;
private:
	virtual void printFormats() = 0;
	virtual std::string readFormat() = 0;

};

