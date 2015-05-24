#ifndef HAKO_ENGINE_TASK_H
#define HAKO_ENGINE_TASK_H


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
			{ this->entry_point = entry_point; }

		Hako::Callback<void, Hako::Engine*> get_entry_point()
			{ return this->entry_point; }


	protected:
		Hako::Callback<void, Hako::Engine*> entry_point;
	};


	// Manages a collection of tasks.
	class TaskManager
	{
	public:
		Hako::DS::Vector<Task> tasks;

		void init (Hako::Engine* engine);
		void add  (Task task);
	};
}


#endif

