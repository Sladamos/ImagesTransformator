#include <algorithm>
#include "ChangeFormatOption.h"

ChangeFormatOption::ChangeFormatOption(const std::string& name, std::shared_ptr<Communicator> communicator, const std::vector<std::string>& formats) :
    Option(name, communicator), formats(formats)
{
    this->formats.push_back("Undo");
}

void ChangeFormatOption::execute()
{
    displayText(getSupportedFormats());
    auto format = std::shared_ptr<std::string>(new std::string(handleInput()));
    if (*format != "Undo" && isFormatSupported(*format))
    {
            formatChanged.invoke(format);
    }
}

std::string ChangeFormatOption::getSupportedFormats()
{
    std::string text;
    for (auto format : formats)
    {
        text += format;
    }
    return text;
}

bool ChangeFormatOption::isFormatSupported(const std::string& format)
{
    return std::find(formats.begin(), formats.end(), format) != formats.end();
    
}

std::string ChangeFormatOption::getDescription()
{
    return "Select input image format";
}


