#ifndef HAKO_ENGINE_ENGINE_H
#define HAKO_ENGINE_ENGINE_H


#include <hako/common/mem.h>
#include <hako/engine/task.h>
#include <hako/engine/gfx/gfx.h>
#include <hako/engine/sfx/sfx.h>
#include <hako/engine/input/input.h>
#include <hako/engine/filesys/filesys.h>


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

		Hako::Gfx*         get_gfx();
		Hako::Sfx*         get_sfx();
		Hako::Input*       get_input();
		Hako::FileSys*     get_filesys();
		Hako::MemCallbacks get_mem_callbacks();

		void set_gfx     (Hako::Gfx* gfx);
		void set_sfx     (Hako::Sfx* sfx);
		void set_input   (Hako::Input* input);
		void set_filesys (Hako::FileSys* filesys);

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
		Hako::Gfx*         gfx;
		Hako::Sfx*         sfx;
		Hako::Input*       input;
		Hako::FileSys*     filesys;
	};
}


#endif

