#ifdef HAKO_BUILD_WIN32


#include <hako/application.h>
#include <hako/common/debug.h>
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
	// Main loop. Can only break when user quits the application.
	//
	int fixed_timer = 0;
	int fixed_cycles_per_second = 30;
	while (true)
	{
		//
		// Get current timestamp using Windows functions.
		//
		LARGE_INTEGER timer_frequency;
		LARGE_INTEGER timer_starttime;
		LARGE_INTEGER timer_endtime;
		LARGE_INTEGER timer_elapsed_microseconds;
		QueryPerformanceFrequency(&timer_frequency);
		QueryPerformanceCounter(&timer_starttime);

		//
		// Process frame-syncronized tasks.
		//

		// interpolation factor: (fixed_timer / float(1000000 / fixed_cycles_per_second))
		for (unsigned int i = 0; i < engine.framesync_tasks.tasks.get_length(); i++)
			engine.framesync_tasks.tasks.get_element(i).get_entry_point().call(&engine);

		//
		// Render graphics.
		//
		window->process_events();
		if (window->did_user_quit())
			break;

		//
		// Sleep for the remaining of frame.
		//
		QueryPerformanceCounter(&timer_endtime);
		timer_elapsed_microseconds.QuadPart  = timer_endtime.QuadPart - timer_starttime.QuadPart;
		timer_elapsed_microseconds.QuadPart *= 1000;
		timer_elapsed_microseconds.QuadPart /= timer_frequency.QuadPart;
		int elapsedMilliseconds = int(timer_elapsed_microseconds.QuadPart);
		if (elapsedMilliseconds < 1000 / 60) Sleep((1000 / 60) - int(elapsedMilliseconds));

		//
		// Advance fixed timer, and execute fixed-syncronized tasks.
		//
		QueryPerformanceCounter(&timer_endtime);
		timer_elapsed_microseconds.QuadPart  = timer_endtime.QuadPart - timer_starttime.QuadPart;
		timer_elapsed_microseconds.QuadPart *= 1000000;
		timer_elapsed_microseconds.QuadPart /= timer_frequency.QuadPart;

		fixed_timer += int(timer_elapsed_microseconds.QuadPart);
		while (fixed_timer >= 1000000 / fixed_cycles_per_second)
		{
			fixed_timer -= 1000000 / fixed_cycles_per_second;
			for (unsigned int i = 0; i < engine.fixedsync_tasks.tasks.get_length(); i++)
				engine.fixedsync_tasks.tasks.get_element(i).get_entry_point().call(&engine);
		}

		//
		// Count frames-per-second rate.
		//
		/*QueryPerformanceCounter(&nEndTime);
		elapsedMicroseconds.QuadPart = nEndTime.QuadPart - nBeginTime.QuadPart;
		elapsedMicroseconds.QuadPart *= 1000000;
		elapsedMicroseconds.QuadPart /= nFreq.QuadPart;

		highFreqFramesPerSecond = 1000000.0f / (elapsedMicroseconds.QuadPart);

		frameCounter++;
		frameTimer += int(elapsedMicroseconds.QuadPart);
		if (frameTimer >= 1000000)
		{
			framesPerSecond = frameCounter;
			frameCounter = 0;
			frameTimer -= 1000000;
		}*/
	}

	window->shutdown();

	return 0;
}



#endif

