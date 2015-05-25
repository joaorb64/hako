#include <hako/application.h>
#include <hako/common/debug.h>
#include <stdio.h>


void test_fixed_task(void* unused, Hako::Engine* engine);


Hako::Options* Hako::Application::on_startup(Hako::Engine* engine)
{
	HAKO_UNUSED(engine);

	printf("Hako::Application::on_startup\n");

	return nullptr;
}


void Hako::Application::on_ready(Hako::Engine* engine)
{
	Hako::Callback<void, Hako::Engine*> fixed_task_callback;
	fixed_task_callback.init(nullptr, test_fixed_task);

	Hako::Task fixed_task;
	fixed_task.init(fixed_task_callback);

	engine->task_add_fixedsync(fixed_task);

	printf("Hako::Application::on_ready\n");
}


void test_fixed_task(void* unused, Hako::Engine* engine)
{
	HAKO_UNUSED(unused);
	HAKO_UNUSED(engine);
	printf("Hako::Application::test_fixed_task\n");
}
