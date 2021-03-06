#include "ThreadManager.h"

namespace BE
{
	ThreadManager::ThreadManager() noexcept
		: threads(), tasks(), cv(), taskMutex(), isEnd(false) {}

	void ThreadManager::Init()
	{
		auto threadNum = std::thread::hardware_concurrency();
		if (threadNum == 0)
		{
			throw SystemException
			{
				TEXT("Hardware Concurrency is 0"),
				Exception::MessageType::Shallow
			};
		}

		threads.reserve(threadNum);

		while (threadNum--)
			threads.emplace_back([this]() { ThreadWork(); });
	}

	void ThreadManager::Release() noexcept
	{
		isEnd = true;
		cv.notify_all();

		for (auto& t : threads)
			t.join();
	}

	void ThreadManager::ThreadWork() noexcept
	{
		while (true)
		{
			std::unique_lock<std::mutex> lock{ taskMutex };
			cv.wait(lock, [this]() { return !tasks.empty() || isEnd; });
			if (isEnd && tasks.empty()) return;

			auto&& task = Move(tasks.front());
			tasks.pop();
			lock.unlock();
			task();
		}
	}
}