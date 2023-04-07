#include "Event.h"

void Event::addListener(std::function<void()> listener)
{
	listeners.push_back(listener);
}

void Event::invoke()
{
	for (auto listener : listeners)
		listener();
}

void Event::operator+=(std::function<void()> listener)
{
	addListener(listener);
}
