#pragma once
#include "Event.h"
class Notifier
{
public:
	void notifyListeners()
	{
		notified.invoke();
	}

	const Event notified;
};