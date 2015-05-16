#include <hako/common/task.h>
#include <hako/common/engine.h>


void Hako::TaskManager::init(Hako::Engine* engine)
{
	m_fixed_tasks.init_mem(
		&engine->m_mem_alloc_callback,
		&engine->m_mem_realloc_callback,
		&engine->m_mem_free_callback);

	m_frame_tasks.init_mem(
		&engine->m_mem_alloc_callback,
		&engine->m_mem_realloc_callback,
		&engine->m_mem_free_callback);

	m_independent_tasks.init_mem(
		&engine->m_mem_alloc_callback,
		&engine->m_mem_realloc_callback,
		&engine->m_mem_free_callback);

	m_noreturn_tasks.init_mem(
		&engine->m_mem_alloc_callback,
		&engine->m_mem_realloc_callback,
		&engine->m_mem_free_callback);

	m_fixed_tasks      .init_elements(0);
	m_frame_tasks      .init_elements(0);
	m_independent_tasks.init_elements(0);
	m_noreturn_tasks   .init_elements(0);
}


void Hako::TaskManager::add_fixed_syncronized(Task task)
{
	m_fixed_tasks.add(task);
}


void Hako::TaskManager::add_frame_syncronized(Task task)
{
	m_frame_tasks.add(task);
}


void Hako::TaskManager::add_independent(Task task)
{
	m_independent_tasks.add(task);
}


void Hako::TaskManager::add_noreturn(Task task)
{
	m_noreturn_tasks.add(task);
}
