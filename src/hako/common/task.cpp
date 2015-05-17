#include <hako/common/task.h>
#include <hako/common/engine.h>


void Hako::TaskManager::init(Hako::Engine* engine)
{
	m_tasks.init(engine->m_mem_callbacks, 0);
}


void Hako::TaskManager::add(Hako::Callback<void, Hako::Engine*> callback)
{
	Task task;
	task.m_entry_point = callback;
	m_tasks.add(task);
}
