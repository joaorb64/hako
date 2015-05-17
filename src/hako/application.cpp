#include <hako/application.h>
#include <hako/common/debug.h>
#include <stdio.h>


void test_fixed_task(Hako::Engine* engine);


Hako::Options* Hako::Application::init_start(Hako::Engine* engine)
{
	HAKO_UNUSED(engine);

	printf("Hako init_start!\n");

	return nullptr;
}


void Hako::Application::init_end(Hako::Engine* engine)
{
	static Hako::FunctionCallback<void, Hako::Engine*> fixed_task;
	fixed_task.init(test_fixed_task);
	engine->m_fixedsync_tasks.add(&fixed_task);

	printf("Hako init_end!\n");
}


void test_fixed_task(Hako::Engine* engine)
{
	HAKO_UNUSED(engine);
	printf("Hako fixed_task!\n");
}
