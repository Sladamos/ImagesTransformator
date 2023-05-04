#include "ChangeFilterOption.h"
#include "SobelMasksOperator.h"
#include "DampelMasksOperator.h"

using namespace std;

ChangeFilterOption::ChangeFilterOption(const string& name, shared_ptr<Communicator> communicator) : 
    Option(name, communicator)
{
    auto masksOperator = shared_ptr<MasksOperator>(new SobelMasksOperator());
    filters.insert({ masksOperator->getName(), masksOperator });
    masksOperator = shared_ptr<MasksOperator>(new DampelMasksOperator());
    filters.insert({ masksOperator->getName(), masksOperator });
}

void ChangeFilterOption::execute()
{
    displayText("Select transformator filter from below filters.");
    displayText(getSupportedFilters());
    auto filter = shared_ptr<string>(new string(handleInput()));
    if (*filter != "Undo" && isFilterSupported(*filter))
    {
        auto masksOperator = filters[*filter];
        auto masks = masksOperator->getMasks();
        filterChanged.invoke(shared_ptr<vector<Mask>>(new vector<Mask>(masks)));
    }
}

string ChangeFilterOption::getDescription()
{
    if (currentFilter != nullptr)
    {
        return "Select filter for transformator, current filter: " + *currentFilter;
    }
    else
    {
        return "Select filter for transformator, current filter: undefined";
    }
}

string ChangeFilterOption::getSupportedFilters()
{
    string supportedFilters;
    for (auto& kv : this->filters)
    {
        supportedFilters += kv.first + "\n";
    }
    supportedFilters.pop_back();
    return supportedFilters;
}

bool ChangeFilterOption::isFilterSupported(const string& filter)
{
    return filters.count(filter);
}
