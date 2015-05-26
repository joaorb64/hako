#include <hako/engine/engine.h>


void Hako::Engine::init()
{
    this->mem_callbacks.alloc_callback   .init(this, Hako::Engine::mem_alloc);
    this->mem_callbacks.realloc_callback .init(this, Hako::Engine::mem_realloc);
    this->mem_callbacks.free_callback    .init(this, Hako::Engine::mem_free);

	this->independent_tasks .init(this);
	this->noreturn_tasks    .init(this);
	this->fixedsync_tasks   .init(this);
	this->framesync_tasks   .init(this);

	this->gfx     = nullptr;
	this->sfx     = nullptr;
	this->input   = nullptr;
	this->filesys = nullptr;

	this->frame_steps_executed             = 0;
	this->fixed_steps_executed             = 0;
	this->fixed_milliseconds_since_startup = 0;
	this->frame_steps_per_second           = 0;
	this->fixed_steps_per_second           = 0;

	this->desired_frame_steps_per_second   = 60;
	this->desired_fixed_steps_per_second   = 30;
}



void Hako::Engine::task_add_fixedsync(Hako::Task task)
{
	this->fixedsync_tasks.add(task);
}



void Hako::Engine::task_add_framesync(Hako::Task task)
{
	this->framesync_tasks.add(task);
}



Hako::Gfx::Manager* Hako::Engine::get_gfx()
{
	return this->gfx;
}



Hako::Sfx::Manager* Hako::Engine::get_sfx()
{
	return this->sfx;
}



Hako::Input::Manager* Hako::Engine::get_input()
{
	return this->input;
}



Hako::FileSys::Manager* Hako::Engine::get_filesys()
{
	return this->filesys;
}



Hako::MemCallbacks Hako::Engine::get_mem_callbacks()
{
	return this->mem_callbacks;
}



int Hako::Engine::get_frame_steps_executed()
{
	return this->frame_steps_executed;
}



int Hako::Engine::get_frame_steps_per_second()
{
	return this->frame_steps_per_second;
}



int Hako::Engine::get_fixed_steps_per_second()
{
	return this->fixed_steps_per_second;
}



int Hako::Engine::get_fixed_steps_executed()
{
	return this->fixed_steps_executed;
}



int Hako::Engine::get_fixed_milliseconds_since_startup()
{
	return this->fixed_milliseconds_since_startup;
}




void Hako::Engine::set_desired_frame_steps_per_second(int desired_value)
{
	this->desired_frame_steps_per_second = desired_value;
}



void Hako::Engine::set_desired_fixed_steps_per_second(int desired_value)
{
	this->desired_fixed_steps_per_second = desired_value;
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
