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
		void init(Hako::Engine* engine, Hako::Callback<void, Hako::Engine*> entry_point);
		Hako::Callback<void, Hako::Engine*> get_entry_point();

		void add_dependency             (Task* task);
		void add_concurrent_prohibition (Task* task);


	protected:
		Hako::Callback<void, Hako::Engine*> entry_point;
		Hako::DS::Vector<Task*> dependency_list;
		Hako::DS::Vector<Task*> concurrent_prohibition_list;
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

