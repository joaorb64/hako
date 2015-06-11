#ifdef HAKO_PLATFORM_WIN32


#include <hako/engine/app.h>
#include <hako/common/debug.h>
#include <hako/engine/engine.h>
#include <windows.h>
#include "window_opengl.h"


int main(int argc, char** argv)
{
	HAKO_UNUSED(argc);
	HAKO_UNUSED(argv);

	//
	// Set up an instance of the engine.
	//
	Hako::Engine engine;
	engine.init();

	//
	// Initialize only the filesystem module.
	//
	engine.filesys.init(&engine);

	//
	// Call the application's on_startup function.
	//
	void* userdata = nullptr;
	Hako::App::on_startup(&userdata, &engine);

	//
	// Initialize other modules.
	//
	engine.input.init (&engine);
	engine.gfx  .init (&engine);

	//
	// Create a Win32 window and a render context.
	//
	Hako::Win32::Window* window;
#ifdef HAKO_MODULE_OPENGL
		Hako::Win32::WindowOpenGL window_opengl;
		window = &window_opengl;
#endif
	window->init(&engine);

	//
	// Call the application's on_ready function.
	//
	Hako::App::on_ready(userdata, &engine);

	//
	// Timing variables.
	//
	int fixed_step_available_microseconds = 0;
	int frame_step_available_microseconds = 0;
	int fps_counter_last_frame_count      = 0;
	int fps_counter_last_fixed_count      = 0;
	int fps_counter_timestamp             = 0;
	int total_microseconds_running        = 0;

	//
	// Get current timestamp using Windows functions.
	//
	LARGE_INTEGER win32_highrestimer_frequency;
	LARGE_INTEGER win32_highrestimer_last;
	QueryPerformanceFrequency(&win32_highrestimer_frequency);
	QueryPerformanceCounter(&win32_highrestimer_last);

	//
	// Main loop. Can only break when user quits the application.
	//
	while (true)
	{
		//
		// Get current timestamp and time delta.
		//
		LARGE_INTEGER win32_highrestimer_current;
		QueryPerformanceCounter(&win32_highrestimer_current);

		long long int elapsed_microseconds;
		elapsed_microseconds = win32_highrestimer_current.QuadPart - win32_highrestimer_last.QuadPart;
		elapsed_microseconds *= 1000000;
		elapsed_microseconds /= win32_highrestimer_frequency.QuadPart;

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
		window->render(&engine);
		engine.gfx.commandlist_clear();

		//
		// Update input.
		//
		engine.input.process();

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
			engine.frame_steps_per_second = engine.frame_steps_executed - fps_counter_last_frame_count;
			fps_counter_last_frame_count = engine.frame_steps_executed;

			engine.fixed_steps_per_second = engine.fixed_steps_executed - fps_counter_last_fixed_count;
			fps_counter_last_fixed_count = engine.fixed_steps_executed;

			fps_counter_timestamp -= 1000000;
		}

		//
		// Sleep for the rest of frame.
		//
		LARGE_INTEGER win32_highrestimer_current_sleep;
		QueryPerformanceCounter(&win32_highrestimer_current_sleep);
		elapsed_microseconds  = win32_highrestimer_current_sleep.QuadPart - win32_highrestimer_last.QuadPart;
		elapsed_microseconds *= 1000000;
		elapsed_microseconds /= win32_highrestimer_frequency.QuadPart;

		// FIXME: Sleep for slightly shorter than a frame to
		// account for vsync off-timings.
		if (elapsed_microseconds < 1000000 / int(engine.desired_frame_steps_per_second * 1.1f))
			Sleep(int(1000 / (engine.desired_frame_steps_per_second * 1.1f)) - (elapsed_microseconds / 1000));

		//
		// Set the current timestamp as the last frame's timestamp.
		//
		win32_highrestimer_last = win32_highrestimer_current;
	}

	window->shutdown();

	return 0;
}



#endif

