#ifndef HAKO_COMMON_MEM_H
#define HAKO_COMMON_MEM_H


#include <hako/common/callback.h>


namespace Hako
{
	typedef void*(*MemAllocFunctionPtr)(
		unsigned int size_in_bytes,
		unsigned int alignment_in_bytes);


	typedef void*(*MemReallocFunctionPtr)(
		void* old_ptr,
		unsigned int old_size_in_bytes,
		unsigned int old_alignment_in_bytes,
		unsigned int new_size_in_bytes,
		unsigned int new_alignment_in_bytes);


	typedef void (*MemFreeFunctionPtr)(
		void* ptr);


	typedef Hako::Callback<void*, unsigned int, unsigned int>
		MemAllocCallback;

	typedef Hako::Callback<void*, void*, unsigned int, unsigned int, unsigned int, unsigned int>
		MemReallocCallback;

	typedef Hako::Callback<void, void*>
		MemFreeCallback;


	struct MemCallbacks
	{
		MemAllocCallback   m_alloc;
		MemReallocCallback m_realloc;
		MemFreeCallback    m_free;
	};
}


#endif
