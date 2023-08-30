#include "SelectOutputNameOption.h"

SelectOutputNameOption::SelectOutputNameOption(const std::string& name, std::shared_ptr<Communicator> communicator) :
    Option(name, communicator)
{
    outputName = nullptr;
    outputNameChanged += [this](auto name) {this->onOutputNameChanged(name); };
}

void SelectOutputNameOption::connectNotifiers(std::shared_ptr<OneArgNotifier<std::string>> formatChangedNotifier)
{
    formatChangedNotifier->notified += [this](auto format) {this->onFormatChanged(); };
}

void SelectOutputNameOption::execute()
{
    displayText("Give output image name.");
    std::string imageName = handleInput();
    auto outputName = std::shared_ptr<std::string>(new std::string(imageName));
    outputNameChanged.invoke(outputName);
}

std::string SelectOutputNameOption::getDescription()
{
    if (outputName != nullptr)
    {
        return "Select output image name, current name: " + *outputName;
    }
    else
    {
        return "Select output image name, current name: undefined";
    }
}

void SelectOutputNameOption::onFormatChanged(std::shared_ptr<std::string> newFormat)
{
    outputNameChanged.invoke(nullptr);
}

void SelectOutputNameOption::onOutputNameChanged(std::shared_ptr<std::string> newOutputName)
{
    outputName = newOutputName;
}
