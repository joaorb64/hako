#ifndef HAKO_COMMON_TASK_H
#define HAKO_COMMON_TASK_H


#include <hako/common/ds/vector.h>
#include <hako/common/callback.h>


namespace Hako
{
	class Engine;


	class Task
	{
		friend class TaskManager;

	public:
		void init(Hako::Callback<void, Hako::Engine*> entry_point)
			{ m_entry_point = entry_point; }

		Hako::Callback<void, Hako::Engine*> get_entry_point()
			{ return m_entry_point; }


	protected:
		Hako::Callback<void, Hako::Engine*> m_entry_point;
	};


	// Manages a collection of tasks.
	class TaskManager
	{
	public:
		Hako::DS::Vector<Task> m_tasks;

		void init (Hako::Engine* engine);
		void add  (Task task);
	};
}


#endif

