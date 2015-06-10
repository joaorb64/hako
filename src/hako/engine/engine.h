#ifndef HAKO_ENGINE_ENGINE_H
#define HAKO_ENGINE_ENGINE_H


#include <hako/common/mem.h>
#include <hako/engine/task.h>
#include <hako/engine/bindings.h>
#include <hako/common/references.h>


int main(int argc, char** argv);


namespace Hako
{
	// Holds general engine information.
	class Engine
	{
		friend int (::main)(int argc, char** argv);

	public:
		void init();
		void task_add_fixedsync(Hako::Task task);
		void task_add_framesync(Hako::Task task);

		Hako::Gfx::Manager*     get_gfx();
		Hako::Input::Manager*   get_input();
		Hako::FileSys::Manager* get_filesys();
		Hako::MemCallbacks      get_mem_callbacks();

		int  get_frame_steps_executed();
		int  get_fixed_steps_executed();
		int  get_fixed_milliseconds_since_startup();
		int  get_frame_steps_per_second();
		int  get_fixed_steps_per_second();
		void set_desired_frame_steps_per_second(int desired_value);
		void set_desired_fixed_steps_per_second(int desired_value);

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
		TaskManager independent_tasks;
		TaskManager noreturn_tasks;
		TaskManager fixedsync_tasks;
		TaskManager framesync_tasks;

		Hako::MemCallbacks      mem_callbacks;
		Hako::Gfx::Manager      gfx;
		Hako::Input::Manager    input;
		Hako::FileSys::Manager  filesys;

		int desired_frame_steps_per_second;
		int desired_fixed_steps_per_second;
		int frame_steps_executed;
		int frame_steps_per_second;
		int fixed_steps_executed;
		int fixed_steps_per_second;
		int fixed_milliseconds_since_startup;
	};
}


#endif

