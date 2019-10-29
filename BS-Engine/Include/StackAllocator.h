#pragma once

#include "BaseAllocator.h"
#include <limits>

/**
 * @brief Allocator with fixed order of allocation and deallocation
*/
template <class T>
class BS_API StackAllocator final : public BaseAllocator<T>
{
public:
	StackAllocator(size_t count) noexcept;
	~StackAllocator() noexcept;

	T* allocate(size_t n) noexcept override;
	void deallocate(T* ptr, size_t n) noexcept override;

private:
	T* cur;
	T* start;
};

template <class T>
StackAllocator<T>::StackAllocator(size_t count) noexcept
	: BaseAllocator<T>(count),
	cur(nullptr),
	start(nullptr)
{
	cur = start = static_cast<T*>(
		GetMemoryManager()->Allocate(count * sizeof(T)));
}

template <class T>
StackAllocator<T>::~StackAllocator() noexcept
{
	GetMemoryManager()->Deallocate(start, max_size());
}

template <class T>
T* StackAllocator<T>::allocate(size_t n) noexcept
{
	const auto nextCur = cur + n;

	if (nextCur > start + max_size())
		return nullptr;

	std::memset(cur, 0, nextCur - cur);
	const auto* ret = cur;
	cur = nextCur;
	return ret;
}

template <class T>
void StackAllocator<T>::deallocate(T* ptr, size_t n) noexcept
{
	check(cur - n == ptr);
	cur = ptr;
}