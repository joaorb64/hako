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
	static int last_ms = 0;

	HAKO_UNUSED(unused);
	HAKO_UNUSED(engine);

	if (engine->get_fixed_milliseconds_since_startup() - last_ms > 1000)
	{
		last_ms = engine->get_fixed_milliseconds_since_startup();
		printf("Hako::Application::test_fixed_task (%4d frames/s, %4d fixed/s, %8d ms since start)\n",
			engine->get_frame_steps_per_second(),
			engine->get_fixed_steps_per_second(),
			engine->get_fixed_milliseconds_since_startup());
	}
}
