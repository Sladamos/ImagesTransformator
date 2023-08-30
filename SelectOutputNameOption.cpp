#include "SelectOutputNameOption.h"

SelectOutputNameOption::SelectOutputNameOption(const std::string& name, std::shared_ptr<Communicator> communicator) :
    Option(name, communicator)
{
    outputName = nullptr;
}

void SelectOutputNameOption::connectNotifiers(std::shared_ptr<OneArgNotifier<std::string>> formatChangedNotifier, std::shared_ptr<OneArgNotifier<std::string>> outputNameChangedNotifier)
{
    formatChangedNotifier->notified += [this](auto format) {this->onFormatChanged(); };
    outputNameChangedNotifier->notified += [this](auto name) {this->onOutputNameChanged(name); };
    this->outputNameChangedNotifier = outputNameChangedNotifier;
}

void SelectOutputNameOption::execute()
{
    displayText("Give output image name.");
    std::string imageName = handleInput();
    auto outputName = std::shared_ptr<std::string>(new std::string(imageName));
    outputNameChangedNotifier->notifyListeners(outputName);
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
    outputNameChangedNotifier->notifyListeners(nullptr);
}

void SelectOutputNameOption::onOutputNameChanged(std::shared_ptr<std::string> newOutputName)
{
    outputName = newOutputName;
}
