#include <hako/common/engine.h>
#include <hako/common/task.h>


void Hako::Engine::init()
{
    m_mem_callbacks.m_alloc  .init(this, Engine::mem_alloc);
    m_mem_callbacks.m_realloc.init(this, Engine::mem_realloc);
    m_mem_callbacks.m_free   .init(this, Engine::mem_free);

	m_independent_tasks   .init(this);
	m_noreturn_tasks      .init(this);
	m_fixedsync_tasks     .init(this);
	m_framesync_tasks     .init(this);
}


void* Hako::Engine::mem_alloc(
	void* engine,
	unsigned int size_in_bytes,
	unsigned int alignment_in_bytes)
{
	HAKO_UNUSED(engine);
	HAKO_UNUSED(alignment_in_bytes);
	return malloc(size_in_bytes);
}


void* Hako::Engine::mem_realloc(
	void* engine,
	void* old_ptr,
	unsigned int old_size_in_bytes,
	unsigned int old_alignment_in_bytes,
	unsigned int new_size_in_bytes,
	unsigned int new_alignment_in_bytes)
{
	HAKO_UNUSED(engine);
	HAKO_UNUSED(old_size_in_bytes);
	HAKO_UNUSED(old_alignment_in_bytes);
	HAKO_UNUSED(new_alignment_in_bytes);
	return realloc(old_ptr, new_size_in_bytes);
}


void Hako::Engine::mem_free(
	void* engine,
	void* ptr)
{
	HAKO_UNUSED(engine);
	free(ptr);
}
