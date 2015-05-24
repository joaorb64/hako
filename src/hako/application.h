#ifndef HAKO_COMMON_APPLICATION_H
#define HAKO_COMMON_APPLICATION_H


#include <hako/common/options.h>
#include <hako/common/engine.h>


namespace Hako
{
	// Holds user application data.
	class Application
	{
	public:
		// Called when the engine first starts. Should return an Options
		// structure containing startup directives, or nullptr.
		static Hako::Options* on_startup(Hako::Engine* engine);

		// Called after modules have loaded, but before main loop
		// has started.
		static void on_ready(Hako::Engine* engine);
	};
}


#endif

