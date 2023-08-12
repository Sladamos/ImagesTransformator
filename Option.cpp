#include "Option.h"
#include "StringsOperator.h"

using namespace std;

Option::Option(const std::string& name, std::shared_ptr<Communicator> communicator) : name(name), communicator(communicator)
{
}

std::string Option::toString()
{
    StringsOperator decorator;
    stringstream ss;
 
    ss << decorator.decorateString(name) << ": " << getDescription();
    return ss.str();
}

std::string Option::getName()
{
    return name;
}

void Option::displayText(const std::string& text)
{
    communicator->displayText(text);
}

void Option::displayLines(const std::vector<std::string>& lines)
{
    stringstream ss;
    StringsOperator decorator;
    int index = 1;
    for (auto& line : lines)
    {
        ss << index << ". " << decorator.decorateString(line) << "\n";
        index++;
    }

    string text = ss.str();
    text.pop_back();
    communicator->displayText(text);
}

void Option::displayError(const std::string& text)
{
    communicator->displayError(text);
}

std::string Option::handleInput()
{
    return communicator->handleInput();
}
