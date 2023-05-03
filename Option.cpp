#include "Option.h"
using namespace std;

Option::Option(const std::string& name, std::shared_ptr<Communicator> communicator) : name(name), communicator(communicator)
{
}

std::string Option::toString()
{
    stringstream ss;
    ss << "[" << name << setw(10) << "]" << ": " << getDescription();
    return ss.str();
}

void Option::displayText(const std::string& text)
{
    communicator->displayText(text);
}

std::string Option::handleInput()
{
    return communicator->handleInput();
}
