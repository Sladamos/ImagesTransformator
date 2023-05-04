#include <algorithm>
#include "ChangeFormatOption.h"

ChangeFormatOption::ChangeFormatOption(const std::string& name, std::shared_ptr<Communicator> communicator, const std::vector<std::string>& formats) :
    Option(name, communicator), formats(formats)
{
    this->formats.push_back("Undo");
    currentFormat = nullptr;
    formatChanged += [this](auto format) {this->onFormatChanged(format); };
}

void ChangeFormatOption::execute()
{
    displayText("Select images format from below formats.");
    displayText(getSupportedFormats());
    auto format = std::shared_ptr<std::string>(new std::string(handleInput()));
    if (*format != "Undo" && isFormatSupported(*format))
    {
        formatChanged.invoke(format);
    }
    else if (currentFormat == nullptr)
    {
        format = std::shared_ptr<std::string>(new std::string(formats[0]));
        formatChanged.invoke(format);
    }
}

std::string ChangeFormatOption::getSupportedFormats()
{
    std::string text;
    for (auto format : formats)
    {
        text += format + "\n";
    }
    text.pop_back();
    return text;
}

bool ChangeFormatOption::isFormatSupported(const std::string& format)
{
    return std::find(formats.begin(), formats.end(), format) != formats.end();
    
}

void ChangeFormatOption::onFormatChanged(std::shared_ptr<std::string> newFormat)
{
    currentFormat = newFormat;
}

std::string ChangeFormatOption::getDescription()
{
    return "Select images format, current format: " + *currentFormat;
}


