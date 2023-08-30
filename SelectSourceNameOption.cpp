#include "SelectSourceNameOption.h"

SelectSourceNameOption::SelectSourceNameOption(const std::string& name, std::shared_ptr<Communicator> communicator) :
    Option(name, communicator)
{
    sourceName = nullptr;
}

void SelectSourceNameOption::connectNotifiers(std::shared_ptr<OneArgNotifier<std::string>> formatChangedNotifier, std::shared_ptr<OneArgNotifier<std::string>> sourceNameChangedNotifier)
{
    formatChangedNotifier->notified += [this](auto format) {this->onFormatChanged(); };
    sourceNameChangedNotifier->notified += [this](auto name) {this->onSourceNameChanged(name); };
    this->sourceNameChangedNotifier = sourceNameChangedNotifier;
}

void SelectSourceNameOption::execute()
{
    displayText("Give source image name.");
    std::string imageName = handleInput();
    auto sourceName = std::shared_ptr<std::string>(new std::string(imageName));
    sourceNameChangedNotifier->notifyListeners(sourceName);
}

std::string SelectSourceNameOption::getDescription()
{
    if (sourceName != nullptr)
    {
        return "Select source image name, current name: " + *sourceName;
    }
    else
    {
        return "Select source image name, current name: undefined";
    }
}

void SelectSourceNameOption::onFormatChanged(std::shared_ptr<std::string> newFormat)
{
    sourceNameChangedNotifier->notifyListeners(nullptr);
}

void SelectSourceNameOption::onSourceNameChanged(std::shared_ptr<std::string> newSourceName)
{
    sourceName = newSourceName;
}
