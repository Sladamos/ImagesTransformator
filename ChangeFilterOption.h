#pragma once
#include <vector>
#include <map>
#include "Option.h"
#include "OneArgEvent.h"
#include "OneArgNotifier.h"
#include "MasksOperator.h"
class ChangeFilterOption : public Option
{
public:
	ChangeFilterOption(const std::string& name, std::shared_ptr<Communicator> communicator, const std::string& masksPath);
	void connectNotifiers(std::shared_ptr<OneArgNotifier<std::vector<Mask>>> filterChangedNotifier);
	virtual void execute() override;
	virtual std::string getDescription() override;
private:
	std::shared_ptr<std::string> getSelectedFilter();
	std::vector<std::string> getSupportedFilters();
	bool isFilterSupported(const std::string& filter);

	std::shared_ptr<std::string> currentFilter;
	std::map<std::string, std::shared_ptr<MasksOperator>> filters;
	std::shared_ptr<OneArgNotifier<std::vector<Mask>>> filterChangedNotifier;
};

