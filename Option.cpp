#include "Option.h"
#include "StringsDecorator.h"
const int Option::EXPECTED_OPTION_WIDTH = 9;

using namespace std;

Option::Option(const std::string& name, std::shared_ptr<Communicator> communicator) : name(name), communicator(communicator)
{
}

std::string Option::toString()
{
    StringsDecorator decorator;
    stringstream ss;
 
    ss << decorator.squareBracketDecorateString(name, EXPECTED_OPTION_WIDTH) << ": " << getDescription();
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
    StringsDecorator decorator;
    int index = 1;
    for (auto& line : lines)
    {
        ss << index << ". " << decorator.squareBracketDecorateString(line, EXPECTED_OPTION_WIDTH) << "\n";
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
