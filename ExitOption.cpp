#include "ExitOption.h"

ExitOption::ExitOption(const std::string& name, std::shared_ptr<Communicator> communicator) : Option(name, communicator)
{
}

void ExitOption::connectNotifiers(std::shared_ptr<Notifier> programExitedNotifier)
{
    this->programExitedNotifier = programExitedNotifier;
}

std::string ExitOption::getDescription()
{
    return "Exit program";
}

void ExitOption::execute()
{
    programExitedNotifier->notifyListeners();
}
