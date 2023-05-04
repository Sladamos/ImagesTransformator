#pragma once
#include <iostream>
#include "FormatSelector.h"
class ConsoleFormatSelector : public FormatSelector
{
public:
	ConsoleFormatSelector(const std::vector<std::string>& imagesFormats);
private:
	virtual void printFormats() override;
	virtual std::string readFormat() override;
};

