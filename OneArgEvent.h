#pragma once
#include <memory>
#include <vector>
#include <functional>
template <typename T>
class OneArgEvent
{
public:
	void addListener(std::function<void(std::shared_ptr<T>)> listener) const
	{
		listeners.push_back(listener);
	}

	void invoke(std::shared_ptr<T> arg) const
	{
		for (auto listener : listeners)
			listener(arg);
	}
	void operator +=(std::function<void(std::shared_ptr<T>)> listener) const
	{
		addListener(listener);
	}
private:
	mutable std::vector<std::function<void(std::shared_ptr<T>)>> listeners;
};

