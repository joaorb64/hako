#ifndef HAKO_COMMON_ENGINE_H
#define HAKO_COMMON_ENGINE_H


#include <hako/common/mem.h>
#include <hako/common/task.h>
#include <hako/common/gfx.h>


namespace Hako
{
	// Holds general engine information.
	class Engine
	{
		friend int main(int argc, char** argv);

	public:
		Hako::MemCallbacks m_mem_callbacks;

		TaskManager m_independent_tasks;
		TaskManager m_noreturn_tasks;
		TaskManager m_fixedsync_tasks;
		TaskManager m_framesync_tasks;


		void init();
		void task_add_fixedsync(Hako::Task task);
		void task_add_framesync(Hako::Task task);

		Hako::Gfx* gfx();

		void set_gfx(Hako::Gfx* gfx) { m_gfx = gfx; }

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
		Hako::Gfx* m_gfx;
	};
}


#endif

