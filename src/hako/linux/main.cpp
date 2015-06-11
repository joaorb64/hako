#ifdef HAKO_PLATFORM_LINUX


#include <hako/application.h>
#include <hako/common/debug.h>
#include <hako/engine/engine.h>
#include <sys/time.h>
#include <unistd.h>


#ifdef HAKO_MODULE_OPENGL
	#include <hako/opengl/manager.h>
	#include "window_opengl.h"
#endif


int main(int argc, char** argv)
{
	HAKO_UNUSED(argc);
	HAKO_UNUSED(argv);

	//
	// Set up an engine instance.
	//
	Hako::Engine engine;
	engine.init();

	//
	// Initialize only the filesystem module.
	//
	engine.filesys.init(&engine);

	//
	// Call Application's on_startup.
	//
	void* userdata = nullptr;
	Hako::App::on_startup(&userdata, &engine);

	//
	// Initialize other modules.
	//
	engine.input.init(&engine);
	engine.gfx.  init(&engine);

	//
	// Create a Linux window and a render context.
	//
	Hako::Linux::Window* window;
#ifdef HAKO_MODULE_OPENGL
		Hako::Linux::WindowOpenGL window_opengl;
		window = &window_opengl;
#endif
	window->init(&engine);

	//
	// Call Application's on_ready.
	//
	Hako::App::on_ready(userdata, &engine);

	//
	// Timing variables.
	//
	int fixed_step_available_microseconds = 0;
	int frame_step_available_microseconds = 0;
	int fps_counter_last_frame_timestamp  = 0;
	int fps_counter_last_fixed_timestamp  = 0;
	int fps_counter_timestamp             = 0;
	int total_microseconds_running        = 0;

	//
	// Get current timestamp
	//
	timeval highrestimer_last;
	gettimeofday(&highrestimer_last, NULL);

	//
	// Main loop. Can only break when user quits the application.
	//

	while (true)
	{
		//
		// Get current timestamp and time delta.
		//
		timeval highrestimer_current;
		gettimeofday(&highrestimer_current, NULL);

		long long int elapsed_microseconds;
		elapsed_microseconds = (highrestimer_current.tv_sec - highrestimer_last.tv_sec) * 1000000.0
								+ highrestimer_current.tv_usec - highrestimer_last.tv_usec;

		total_microseconds_running += elapsed_microseconds;
		engine.fixed_milliseconds_since_startup = total_microseconds_running / 1000.0;

		//
		// Process window events.
		//
		window->process_events();
		if (window->did_user_quit())
			break;

		//
		// Process frame-syncronized tasks.
		//
		frame_step_available_microseconds += elapsed_microseconds;
		for (unsigned int i = 0; i < engine.framesync_tasks.tasks.get_length(); i++)
			engine.framesync_tasks.tasks.get_element(i).get_entry_point().call(&engine);

		engine.frame_steps_executed += 1;
		engine.gfx.commandlist_clear();

		//
		// Advance fixed timer, and execute fixed-syncronized tasks.
		//
		fixed_step_available_microseconds += elapsed_microseconds;

		int microseconds_per_fixed = 1000000 / engine.desired_fixed_steps_per_second;
		int fixed_per_frame_limit = 120;
		while (fixed_step_available_microseconds >= microseconds_per_fixed && fixed_per_frame_limit > 0)
		{
			fixed_step_available_microseconds -= microseconds_per_fixed;

			for (unsigned int i = 0; i < engine.fixedsync_tasks.tasks.get_length(); i++)
				engine.fixedsync_tasks.tasks.get_element(i).get_entry_point().call(&engine);

			engine.fixed_steps_executed += 1;
			fixed_per_frame_limit -= 1;
		}

		//
		// Count frames-per-second rate.
		//
		fps_counter_timestamp += elapsed_microseconds;

		if (fps_counter_timestamp >= 1000000)
		{
			engine.frame_steps_per_second = engine.frame_steps_executed - fps_counter_last_frame_timestamp;
			fps_counter_last_frame_timestamp = engine.frame_steps_executed;

			engine.fixed_steps_per_second = engine.fixed_steps_executed - fps_counter_last_fixed_timestamp;
			fps_counter_last_fixed_timestamp = engine.fixed_steps_executed;

			fps_counter_timestamp -= 1000000;
		}

		//
		// Sleep for the rest of frame.
		//
		timeval highrestimer_current_sleep;
		gettimeofday(&highrestimer_current_sleep, NULL);
		elapsed_microseconds  = (highrestimer_current_sleep.tv_sec - highrestimer_last.tv_sec) * 1000000.0
								+ highrestimer_current_sleep.tv_usec - highrestimer_last.tv_usec;

		// FIXME: Sleep for slightly shorter than a frame to
		// account for vsync off-timings.
		if (elapsed_microseconds < 1000000 / int(engine.desired_frame_steps_per_second * 1.1f))
			usleep(int(1000 / (engine.desired_frame_steps_per_second * 1.1f)) - (elapsed_microseconds / 1000));

		//
		// Set the current timestamp as the last frame's timestamp.
		//
		highrestimer_last = highrestimer_current;
	}

	window->shutdown();

	return 0;
}


#endif

