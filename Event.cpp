#include "Event.h"

void Event::addListener(std::function<void()> listener) const
{
	listeners.push_back(listener);
}

void Event::invoke() const
{
	for (auto listener : listeners)
		listener();
}

void Event::operator+=(std::function<void()> listener) const
{
	addListener(listener);
}
