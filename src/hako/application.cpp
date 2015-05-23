#include <hako/application.h>
#include <hako/common/debug.h>
#include <stdio.h>


void test_fixed_task(void* unused, Hako::Engine* engine);


Hako::Options* Hako::Application::init_start(Hako::Engine* engine)
{
	HAKO_UNUSED(engine);

	printf("Hako init_start!\n");

	return nullptr;
}


void Hako::Application::init_end(Hako::Engine* engine)
{
	Hako::Callback<void, Hako::Engine*> fixed_task_callback;
	fixed_task_callback.init(nullptr, test_fixed_task);

	Hako::Task fixed_task;
	fixed_task.init(fixed_task_callback);

	engine->task_add_fixedsync(fixed_task);

	printf("Hako init_end!\n");
}


void test_fixed_task(void* unused, Hako::Engine* engine)
{
	HAKO_UNUSED(unused);
	HAKO_UNUSED(engine);
	printf("Hako fixed_task!\n");
}
