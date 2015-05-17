#ifndef HAKO_COMMON_ENGINE_H
#define HAKO_COMMON_ENGINE_H


#include <hako/common/mem.h>
#include <hako/common/task.h>


namespace Hako
{
	// Holds general engine information.
	class Engine
	{
	public:
		Hako::MemCallbacks m_mem_callbacks;

		TaskManager m_independent_tasks;
		TaskManager m_noreturn_tasks;
		TaskManager m_fixedsync_tasks;
		TaskManager m_framesync_tasks;


		void init();

		static void* mem_alloc(
			void* engine,
			unsigned int size_in_bytes,
			unsigned int alignment_in_bytes);

		static void* mem_realloc(
			void* engine,
			void* old_ptr,
			unsigned int old_size_in_bytes,
			unsigned int old_alignment_in_bytes,
			unsigned int new_size_in_bytes,
			unsigned int new_alignment_in_bytes);

		static void mem_free(
			void* engine,
			void* ptr);
	};
}


#endif

