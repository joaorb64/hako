#ifndef HAKO_COMMON_ENGINE_H
#define HAKO_COMMON_ENGINE_H


#include <hako/common/mem.h>
#include <hako/engine/task.h>
#include <hako/engine/gfx.h>


namespace Hako
{
	// Holds general engine information.
	class Engine
	{
	public:
		TaskManager independent_tasks;
		TaskManager noreturn_tasks;
		TaskManager fixedsync_tasks;
		TaskManager framesync_tasks;


		void init();
		void task_add_fixedsync(Hako::Task task);
		void task_add_framesync(Hako::Task task);

		Hako::Gfx* get_gfx();
		Hako::MemCallbacks get_mem_callbacks();

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


	protected:
		Hako::MemCallbacks mem_callbacks;
		Hako::Gfx          gfx;
	};
}


#endif

