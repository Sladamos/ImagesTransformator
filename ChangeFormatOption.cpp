#include <algorithm>
#include <sstream>
#include <string>
#include "ChangeFormatOption.h"

ChangeFormatOption::ChangeFormatOption(const std::string& name, std::shared_ptr<Communicator> communicator, const std::vector<std::string>& formats) :
    Option(name, communicator), formats(formats)
{
    this->formats.push_back("Undo");
    currentFormat = nullptr;
}

void ChangeFormatOption::connectNotifiers(std::shared_ptr<OneArgNotifier<std::string>> formatChangedNotifier)
{
    this->formatChangedNotifier = formatChangedNotifier;
    formatChangedNotifier->notified += [this](auto format) {this->onFormatChanged(format); };
}

void ChangeFormatOption::execute()
{
    displayText("Select images format from below formats.");
    displayLines(formats);
    auto format = getSelectedFormat();

    if (*format != "Undo" && isFormatSupported(*format))
    {
        formatChangedNotifier->notifyListeners(format);
    }
    else if (currentFormat == nullptr)
    {
        format = std::shared_ptr<std::string>(new std::string(formats[0]));
        formatChangedNotifier->notifyListeners(format);
    }
}

std::shared_ptr<std::string> ChangeFormatOption::getSelectedFormat()
{
    auto format = std::shared_ptr<std::string>(new std::string(handleInput())); 
    try
    {
        int index = std::stoi(*format) - 1;
        if (index < formats.size() && index >= 0)
        {
            *format = formats[index];
        }
    }
    catch (std::exception& err)
    {
    }
    return format;
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


