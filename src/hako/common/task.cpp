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

	m_fixed_tasks.init_elements(0);
	m_frame_tasks.init_elements(0);
}
