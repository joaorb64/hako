#include <hako/application.h>
#include <hako/common/debug.h>
#include <stdio.h>


Hako::Options* Hako::Application::init_start(Hako::Engine* engine)
{
	HAKO_UNUSED(engine);

	printf("Hako init_start!\n");

	return nullptr;
}


void Hako::Application::init_end(Hako::Engine* engine)
{
	HAKO_UNUSED(engine);

	printf("Hako init_end!\n");
}
