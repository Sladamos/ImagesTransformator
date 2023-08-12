#pragma once
#include <vector>
#include <map>
#include "Option.h"
#include "OneArgEvent.h"
#include "MasksOperator.h"
class ChangeFilterOption : public Option
{
public:
	ChangeFilterOption(const std::string& name, std::shared_ptr<Communicator> communicator);
	virtual void execute() override;
	virtual std::string getDescription() override;

	const OneArgEvent<std::vector<Mask>> filterChanged;
private:
	std::vector<std::string> getSupportedFilters();
	bool isFilterSupported(const std::string& filter);

	std::shared_ptr<std::string> currentFilter;
	std::map<std::string, std::shared_ptr<MasksOperator>> filters;
};

