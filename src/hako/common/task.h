#ifndef HAKO_COMMON_TASK_H
#define HAKO_COMMON_TASK_H


#include <hako/common/ds/vector.h>


namespace Hako
{
	class Engine;


	// Holds data about a task.
	class Task
	{
		friend class TaskManager;

	public:
		typedef void(*EntryFunctionPtr)(Hako::Engine* engine);

	protected:
		EntryFunctionPtr m_entry_function;
	};


	// Manages a collection of tasks.
	class TaskManager
	{
	public:
		void init                 (Hako::Engine* engine);
		void add_independent      (Task task);
		void add_noreturn         (Task task);
		void add_fixed_syncronized(Task task);
		void add_frame_syncronized(Task task);


	protected:
		Hako::DS::Vector<Task> m_fixed_tasks;
		Hako::DS::Vector<Task> m_frame_tasks;
		Hako::DS::Vector<Task> m_independent_tasks;
		Hako::DS::Vector<Task> m_noreturn_tasks;
	};
}


#endif

