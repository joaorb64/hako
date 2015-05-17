#ifndef HAKO_COMMON_ENGINE_H
#define HAKO_COMMON_ENGINE_H


#include <hako/common/mem.h>
#include <hako/common/task.h>


namespace Hako
{
	// Holds general engine information.
	class Engine
	{
		friend int main(int, char**);


	public:
		Hako::MemberCallback<Engine, void*, unsigned int, unsigned int>
			m_mem_alloc_callback;

		Hako::MemberCallback<Engine, void*, void*, unsigned int, unsigned int, unsigned int, unsigned int>
			m_mem_realloc_callback;

		Hako::MemberCallback<Engine, void, void*>
			m_mem_free_callback;


		void init();

		void* mem_alloc(
			unsigned int size_in_bytes,
			unsigned int alignment_in_bytes);

		void* mem_realloc(
			void* old_ptr,
			unsigned int old_size_in_bytes,
			unsigned int old_alignment_in_bytes,
			unsigned int new_size_in_bytes,
			unsigned int new_alignment_in_bytes);

		void mem_free(
			void* ptr);


		TaskManager m_independent_tasks;
		TaskManager m_noreturn_tasks;
		TaskManager m_fixedsync_tasks;
		TaskManager m_framesync_tasks;
	};
}


#endif

