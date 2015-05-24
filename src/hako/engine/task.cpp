#include <hako/engine/engine.h>


void Hako::TaskManager::init(Hako::Engine* engine)
{
	this->tasks.init(engine->get_mem_callbacks(), 0);
}


void Hako::TaskManager::add(Task task)
{
	this->tasks.add(task);
}
