#pragma once
#include <vector>
#include <functional>

class Event
{
public:
	void addListener(std::function<void()> listener);
	void invoke();

	void operator +=(std::function<void()> listener);
private:
	std::vector<std::function<void()>> listeners;
};

