#include <hako/engine/engine.h>


void Hako::Engine::init()
{
    this->mem_callbacks.alloc_callback   .init(this, Engine::mem_alloc);
    this->mem_callbacks.realloc_callback .init(this, Engine::mem_realloc);
    this->mem_callbacks.free_callback    .init(this, Engine::mem_free);

	this->independent_tasks .init(this);
	this->noreturn_tasks    .init(this);
	this->fixedsync_tasks   .init(this);
	this->framesync_tasks   .init(this);
}



void Hako::Engine::task_add_fixedsync(Hako::Task task)
{
	this->fixedsync_tasks.add(task);
}



void Hako::Engine::task_add_framesync(Hako::Task task)
{
	this->framesync_tasks.add(task);
}



Hako::Gfx* Hako::Engine::get_gfx()
{
	return &this->gfx;
}



Hako::MemCallbacks Hako::Engine::get_mem_callbacks()
{
	return this->mem_callbacks;
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
