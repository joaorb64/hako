#include <hako/common/task.h>
#include <hako/common/engine.h>


void Hako::TaskManager::init(Hako::Engine* engine)
{
	m_tasks.init_mem(
		engine->m_mem_alloc_callback,
		engine->m_mem_realloc_callback,
		engine->m_mem_free_callback);

	m_tasks.init_elements(0);
}


void Hako::TaskManager::add(Hako::Callback<void, Hako::Engine*> callback)
{
	Task task;
	task.m_entry_point = callback;
	m_tasks.add(task);
}
