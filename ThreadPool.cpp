#include "ThreadPool.h"

ThreadPool::ThreadPool(int numberOfThreads)
{
}

void ThreadPool::start()
{
	//odblokuj przyjmowanie tasków i stwórz poola
}

void ThreadPool::queueTask(const std::function<void()>& task)
{
	const std::lock_guard<std::mutex> lock(tasksMutex);
	tasks.push(task);
	//notify all
}

void ThreadPool::safeExit()
{
	//zablokuj przyjmowanie tasków
	//poczekaj na oproznienie kolejki (przy pomocy join)
}

void ThreadPool::join()
{
	for (std::thread thrd : this->threads)
	{
		thrd.join();
	}
}
