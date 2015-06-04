#ifdef HAKO_BUILD_LINUX

#include <hako/application.h>
#include <hako/common/debug.h>
#include "window_opengl.h"
#include <sys/time.h>
#include <unistd.h>


int main(int argc, char** argv)
{
	HAKO_UNUSED(argc);
	HAKO_UNUSED(argv);

	Hako::Engine engine;
	engine.init();

	Hako::Application::on_startup(&engine);

	Hako::Linux::Window* window;
#ifdef HAKO_BUILD_GFXOPENGL
	Hako::Linux::WindowOpenGL window_opengl;
	window = &window_opengl;
#endif
	window->init(&engine);

	Hako::Application::on_ready(&engine);

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
	timeval highrestimer_frequency;
	timeval highrestimer_last;
	gettimeofday(&highrestimer_last, NULL);
	gettimeofday(&highrestimer_frequency, NULL);


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
		elapsed_microseconds = highrestimer_current.tv_usec - highrestimer_last.tv_usec;
		elapsed_microseconds *= 1000000;
		elapsed_microseconds /= highrestimer_frequency.tv_usec;

		total_microseconds_running += elapsed_microseconds;
		engine.fixed_milliseconds_since_startup = total_microseconds_running / 1000;

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
		elapsed_microseconds  = highrestimer_current_sleep.tv_usec - highrestimer_last.tv_usec;
		elapsed_microseconds *= 1000000;
		elapsed_microseconds /= highrestimer_frequency.tv_usec;

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

