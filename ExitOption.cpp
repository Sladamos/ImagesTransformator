#include "ExitOption.h"

ExitOption::ExitOption(const std::string& name, std::shared_ptr<Communicator> communicator) : Option(name, communicator)
{
}

std::string ExitOption::getDescription()
{
    return "Exit program";
}

void ExitOption::execute()
{
    exitProgram.invoke();
}
