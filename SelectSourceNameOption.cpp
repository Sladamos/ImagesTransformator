#include "SelectSourceNameOption.h"

SelectSourceNameOption::SelectSourceNameOption(const std::string& name, std::shared_ptr<Communicator> communicator) :
    Option(name, communicator)
{
    sourceName = nullptr;
    sourceNameChanged += [this](auto name) {this->onSourceNameChanged(name); };
}

void SelectSourceNameOption::execute()
{
    displayText("Give source image name.");
    std::string imageName = handleInput();
    auto sourceName = std::shared_ptr<std::string>(new std::string(imageName));
    sourceNameChanged.invoke(sourceName);
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
    sourceNameChanged.invoke(nullptr);
}

void SelectSourceNameOption::onSourceNameChanged(std::shared_ptr<std::string> newSourceName)
{
    sourceName = newSourceName;
}
