#include <algorithm>
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
    displayLines(getSupportedFilters());
    auto filter = shared_ptr<string>(new string(handleInput()));
    if (*filter != "Undo" && isFilterSupported(*filter))
    {
        currentFilter = filter;
        auto masksOperator = filters[*filter];
        auto masks = masksOperator->getMasks();
        filterChanged.invoke(shared_ptr<vector<Mask>>(new vector<Mask>(masks)));
        displayText("Filter loaded properly");
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

vector<string> ChangeFilterOption::getSupportedFilters()
{
    vector<string> supportedFilters;
    transform(filters.begin(), filters.end(), back_inserter(supportedFilters), [](auto filter) {return filter.first; });
    return supportedFilters;
}

bool ChangeFilterOption::isFilterSupported(const string& filter)
{
    return filters.count(filter);
}
