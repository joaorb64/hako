#ifndef HAKO_COMMON_TASK_H
#define HAKO_COMMON_TASK_H


#include <hako/common/ds/vector.h>
#include <hako/common/callback.h>


namespace Hako
{
	class Engine;


	// Manages a collection of tasks.
	class TaskManager
	{
	public:
		class Task
		{
		public:
			Hako::Callback<void, Hako::Engine*>* m_entry_point;
		};

		Hako::DS::Vector<Task> m_tasks;


		void init (Hako::Engine* engine);
		void add  (Hako::Callback<void, Hako::Engine*>* callback);
	};
}


#endif

