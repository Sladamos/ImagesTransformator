#include "SelectOutputNameOption.h"

SelectOutputNameOption::SelectOutputNameOption(const std::string& name, std::shared_ptr<Communicator> communicator) :
    Option(name, communicator)
{
    outputName = nullptr;
}

void SelectOutputNameOption::execute()
{
    displayText("Give the image name with extension proper to selected format.");
    std::string imageName = handleInput();
    outputName = std::shared_ptr<std::string>(new std::string(imageName));
}

std::string SelectOutputNameOption::getDescription()
{
    if (outputName != nullptr)
    {
        return "Select output image name. Current name: " + *outputName;
    }
    else
    {
        return "Select output image name. Current name: undefined";
    }
}

void SelectOutputNameOption::onFormatChanged(std::shared_ptr<std::string> newFormat)
{
    outputName = nullptr;
}