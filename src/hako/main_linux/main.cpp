#ifdef HAKO_BUILD_LINUX

#include <hako/application.h>
#include <hako/common/debug.h>
#include "gfx_opengl.h"
#include <sys/time.h>


int main(int argc, char** argv)
{
	HAKO_UNUSED(argc);
	HAKO_UNUSED(argv);


	Hako::Engine engine;
	engine.init();


	Hako::Application::init_start(&engine);


	Hako::Gfx* gfx;
#ifdef HAKO_BUILD_GFXOPENGL
	Hako::Linux::GfxOpenGL gfx_opengl;
	gfx = &gfx_opengl;
#endif
	gfx->init(&engine);
    engine.set_gfx(gfx);


	Hako::Application::init_end(&engine);


	//
	// Main loop. Can only break when user quits the application.
	//
	int fixed_timer = 0;
	int fixed_cycles_per_second = 30;
	while (true)
	{
		//
		// Get current timestamp using Linux functions.
		//
		unsigned long long timer_frequency;
		unsigned long long timer_starttime;
		unsigned long long timer_endtime;
		unsigned long long timer_elapsed_microseconds;
		//QueryPerformanceFrequency(&timer_frequency);
		//QueryPerformanceCounter(&timer_starttime);

		gfx->process_events();
		if (gfx->did_user_quit())
			break;

		//
		// Process frame-syncronized tasks.
		//

		// interpolation factor: (fixed_timer / float(1000000 / fixed_cycles_per_second))
		/*for (unsigned int i = 0; i < engine.m_framesync_tasks.m_tasks.get_length(); i++)
			engine.m_framesync_tasks.m_tasks.get_element(i).get_entry_point().call(&engine);

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
			for (unsigned int i = 0; i < engine.m_fixedsync_tasks.m_tasks.get_length(); i++)
				engine.m_fixedsync_tasks.m_tasks.get_element(i).get_entry_point().call(&engine);
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

	gfx->shutdown();

	return 0;
}


void linux_opengl_enable(Display* display, Window* window)
{

}


#endif

