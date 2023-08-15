#pragma once
#include <queue>
#include <vector>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>

class ThreadPool
{
public:
	ThreadPool(int numberOfThreads);
	void start();
	void queueTask(const std::function<void()>& task);
	void safeExit();
private:
	void threadJob();
	void join();

	std::vector<std::thread> threads;
	std::queue<std::function<void()>> tasks;
	std::mutex tasksMutex;
	std::condition_variable cv;
	bool acceptTasks;
	int numberOfThreads;
};

