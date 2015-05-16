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

		enum class Kind
		{
			IndependentOnce,
			IndependentOnceNoReturn,
			AlwaysSynchronizedWithFixedRate,
			AlwaysSynchronizedWithFrameRate
		};


	protected:
		EntryFunctionPtr m_entry_function;
		Kind             m_kind;
	};


	// Manages a collection of tasks.
	class TaskManager
	{
	public:
		void init(Hako::Engine* engine);


	protected:
		Hako::DS::Vector<Task> m_fixed_tasks;
		Hako::DS::Vector<Task> m_frame_tasks;
	};
}


#endif

