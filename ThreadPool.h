#pragma once
#include <queue>
#include <vector>
#include <functional>
#include <thread>
#include <mutex>

class ThreadPool
{
public:
	ThreadPool(int numberOfThreads);
	void start();
	void queueTask(const std::function<void()>& task);
	void safeExit();
private:
	void join();

	std::vector<std::thread> threads;
	std::queue<std::function<void()>> tasks;
	std::mutex tasksMutex;
};

