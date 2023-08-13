#include "ThreadPool.h"

ThreadPool::ThreadPool(int numberOfThreads)
{
}

void ThreadPool::start()
{
	//odblokuj przyjmowanie task�w i stw�rz poola
}

void ThreadPool::queueTask(const std::function<void()>& task)
{
	const std::lock_guard<std::mutex> lock(tasksMutex);
	tasks.push(task);
	//notify all
}

void ThreadPool::safeExit()
{
	//zablokuj przyjmowanie task�w
	//poczekaj na oproznienie kolejki (przy pomocy join)
}

void ThreadPool::join()
{
	for (std::thread thrd : this->threads)
	{
		thrd.join();
	}
}
