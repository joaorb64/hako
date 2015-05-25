#ifdef HAKO_BUILD_WIN32


#include <hako/application.h>
#include <hako/common/debug.h>
#include <hako/engine/engine.h>
#include <hako/engine/filesys/manager_stdio.h>
#include "window_opengl.h"
#include <windows.h>



int main(int argc, char** argv)
{
	HAKO_UNUSED(argc);
	HAKO_UNUSED(argv);

	//
	// Create an instance of the engine.
	//
	Hako::Engine engine;
	engine.init();

	Hako::FileSys::Manager_Stdio filesys;
	filesys.init(&engine);
	engine.filesys = &filesys;

	//
	// Call the application's on_startup function.
	//
	Hako::Application::on_startup(&engine);

	//
	// Create a window and a render context.
	//
	Hako::Win32::Window* window;
#ifdef HAKO_BUILD_GFXOPENGL
	Hako::Win32::WindowOpenGL window_opengl;
	window = &window_opengl;
#endif
	window->init(&engine);

	//
	// Call the application's on_ready function.
	//
	Hako::Application::on_ready(&engine);

	//
	// Timing variables.
	//
	int fixed_timer = 0;
	int frame_timer = 0;
	int fixed_cycles_per_second = 60;
	int fps_timer = 0;
	int total_timer = 0;
	int last_frame_step = 0;
	int last_fixed_step = 0;

	//
	// Get current timestamp using Windows functions.
	//
	LARGE_INTEGER timer_frequency;
	LARGE_INTEGER timer_starttime;
	LARGE_INTEGER timer_endtime;
	QueryPerformanceFrequency(&timer_frequency);
	QueryPerformanceCounter(&timer_starttime);

	//
	// Main loop. Can only break when user quits the application.
	//
	while (true)
	{
		//
		// Get current timestamp and time delta.
		//
		QueryPerformanceCounter(&timer_endtime);

		LARGE_INTEGER timer_elapsed_microseconds;
		timer_elapsed_microseconds.QuadPart  = timer_endtime.QuadPart - timer_starttime.QuadPart;
		timer_elapsed_microseconds.QuadPart *= 1000000;
		timer_elapsed_microseconds.QuadPart /= timer_frequency.QuadPart;
		int elapsed_microseconds = int(timer_elapsed_microseconds.QuadPart);

		timer_starttime = timer_endtime;

		total_timer += elapsed_microseconds;
		engine.fixed_milliseconds_since_startup = total_timer / 1000;

		//
		// Process window events.
		//
		window->process_events();
		if (window->did_user_quit())
			break;

		//
		// Process frame-syncronized tasks.
		//
		frame_timer += elapsed_microseconds;
		for (unsigned int i = 0; i < engine.framesync_tasks.tasks.get_length(); i++)
			engine.framesync_tasks.tasks.get_element(i).get_entry_point().call(&engine);

		engine.frame_steps_executed += 1;

		//
		// Advance fixed timer, and execute fixed-syncronized tasks.
		//
		fixed_timer += elapsed_microseconds;

		int microseconds_per_fixed = 1000000 / fixed_cycles_per_second;
		int fixed_per_frame_limit = 120;
		while (fixed_timer >= microseconds_per_fixed && fixed_per_frame_limit > 0)
		{
			fixed_timer -= microseconds_per_fixed;

			for (unsigned int i = 0; i < engine.fixedsync_tasks.tasks.get_length(); i++)
				engine.fixedsync_tasks.tasks.get_element(i).get_entry_point().call(&engine);

			engine.fixed_steps_executed += 1;
			fixed_per_frame_limit -= 1;
		}

		//
		// Count frames-per-second rate.
		//
		fps_timer += elapsed_microseconds;

		if (fps_timer >= 1000000)
		{
			engine.frame_steps_per_second = engine.frame_steps_executed - last_frame_step;
			last_frame_step = engine.frame_steps_executed;

			engine.fixed_steps_per_second = engine.fixed_steps_executed - last_fixed_step;
			last_fixed_step = engine.fixed_steps_executed;

			fps_timer -= 1000000;
		}

		//
		// Sleep for the rest of frame.
		//
		QueryPerformanceCounter(&timer_endtime);
		timer_elapsed_microseconds.QuadPart  = timer_endtime.QuadPart - timer_starttime.QuadPart;
		timer_elapsed_microseconds.QuadPart *= 1000000;
		timer_elapsed_microseconds.QuadPart /= timer_frequency.QuadPart;
		elapsed_microseconds = int(timer_elapsed_microseconds.QuadPart);

		// FIXME: Sleep for slightly shorter than a frame to
		// account for vsync off-timings.
		if (elapsed_microseconds < 1000000 / 65)
			Sleep((1000 / 65) - (elapsed_microseconds / 1000));
	}

	window->shutdown();

	return 0;
}



#endif

