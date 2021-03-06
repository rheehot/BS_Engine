#pragma once

#include "MemoryManager.h"
#include "MemoryManagerAccesser.h"

namespace BE
{
	class BS_API OneFrameAllocator final : public MemoryManagerAccesser
	{
	public:
		inline void* Allocate(const SizeType n)
		{
			return MemoryManagerAccesser::Get()->GetOneFrameMemory().Allocate(n);
		}
	};
}