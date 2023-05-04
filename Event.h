#pragma once
#include <vector>
#include <functional>

class Event
{
public:
	void addListener(std::function<void()> listener) const;
	void invoke() const;
	void operator +=(std::function<void()> listener) const;
private:
	mutable std::vector<std::function<void()>> listeners;
};

