#pragma once
#include "OneArgEvent.h"
template <typename T>
class OneArgNotifier
{
public:
	void notifyListeners(std::shared_ptr<T> arg)
	{
		notified.invoke(arg);
	}

	const OneArgEvent<T> notified;
};

