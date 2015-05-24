#ifndef HAKO_COMMON_MEM_H
#define HAKO_COMMON_MEM_H


#include <hako/common/callback.h>


namespace Hako
{
	typedef Hako::Callback<void*, unsigned int, unsigned int>
		MemAllocCallback;

	typedef Hako::Callback<void*, void*, unsigned int, unsigned int, unsigned int, unsigned int>
		MemReallocCallback;

	typedef Hako::Callback<void, void*>
		MemFreeCallback;


	struct MemCallbacks
	{
		MemAllocCallback   alloc_callback;
		MemReallocCallback realloc_callback;
		MemFreeCallback    free_callback;
	};
}


#endif
