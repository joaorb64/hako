#include <hako/engine/engine.h>


void Hako::Task::init(Hako::Engine* engine, Hako::Callback<void, Hako::Engine*> entry_point)
{
	this->entry_point = entry_point;
	this->dependency_list             .init(engine->get_mem_callbacks(), 0);
	this->concurrent_prohibition_list .init(engine->get_mem_callbacks(), 0);
}



Hako::Callback<void, Hako::Engine*> Hako::Task::get_entry_point()
{
	return this->entry_point;
}



void Hako::Task::add_dependency(Task* task)
{
	this->dependency_list.add(task);
}



void Hako::Task::add_concurrent_prohibition(Task* task)
{
	this->concurrent_prohibition_list.add(task);
}



void Hako::TaskManager::init(Hako::Engine* engine)
{
	this->tasks.init(engine->get_mem_callbacks(), 0);
}



void Hako::TaskManager::add(Task task)
{
	this->tasks.add(task);
}
