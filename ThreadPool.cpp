#include "ThreadPool.h"

ThreadPool::ThreadPool(int numberOfThreads) : acceptTasks(false), numberOfThreads(numberOfThreads)
{
}

void ThreadPool::start()
{
	safeExit();
	threads = std::vector<std::thread>();
	acceptTasks = true;
	for (int i = 0; i < numberOfThreads; i++)
	{
		std::thread thread([this]() {threadJob(); });
		threads.push_back(std::move(thread));
	}
}

void ThreadPool::queueTask(const std::function<void()>& task)
{
	const std::lock_guard<std::mutex> lock(tasksMutex);
	if (acceptTasks)
	{
		tasks.push(task); 
		cv.notify_one();
	}
}

void ThreadPool::safeExit()
{
	acceptTasks = false;
	cv.notify_all();
	join();
}

void ThreadPool::threadJob()
{
	bool isThreadWorking = true;
	while (isThreadWorking)
	{
		std::unique_lock<std::mutex> lock(tasksMutex);
		while (tasks.size() == 0 && acceptTasks)
		{
			cv.wait(lock);
		}
		if (tasks.size() > 0)
		{
			std::function<void()> task;
			task = tasks.front();
			tasks.pop();
			lock.unlock();
			task();
		}
		else
		{
			isThreadWorking = false;
		}
	}
}

void ThreadPool::join()
{
	for (auto& thread : threads)
	{
		if(thread.joinable())
		{
			thread.join();
		}
	}
}
