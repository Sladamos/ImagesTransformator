#include "ExitOption.h"

ExitOption::ExitOption(const std::string& name) : Option(name)
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
