#ifndef HAKO_ENGINE_ENGINE_H
#define HAKO_ENGINE_ENGINE_H


#include <hako/common/mem.h>
#include <hako/engine/task.h>
#include <hako/engine/bindings.h>


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

		Hako::Gfx::Manager*     get_gfx();
		Hako::Sfx::Manager*     get_sfx();
		Hako::Input::Manager*   get_input();
		Hako::FileSys::Manager* get_filesys();
		Hako::MemCallbacks      get_mem_callbacks();

		void set_gfx     (Hako::Gfx::Manager* gfx);
		void set_sfx     (Hako::Sfx::Manager* sfx);
		void set_input   (Hako::Input::Manager* input);
		void set_filesys (Hako::FileSys::Manager* filesys);

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
		Hako::MemCallbacks       mem_callbacks;
		Hako::Gfx::Manager*      gfx;
		Hako::Sfx::Manager*      sfx;
		Hako::Input::Manager*    input;
		Hako::FileSys::Manager*  filesys;
	};
}


#endif

