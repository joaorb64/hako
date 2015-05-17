#ifdef HAKO_BUILD_WIN32


#include <hako/application.h>
#include <hako/common/debug.h>
#include <windows.h>

#ifdef HAKO_BUILD_GFXOPENGL
	#include <hako/common_gl/render.h>
#endif



// Win32 handle to the main window.
HWND   win32_hwnd_main;
// Win32 handles to the renderer context.
HDC    win32_hdc;
HGLRC  win32_hrc;

// Window callback function used by Win32.
LRESULT CALLBACK win32_window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// Win32 OpenGL setup.
void win32_opengl_enable (HWND hwnd, HDC* hdc, HGLRC* hrc);
void win32_opengl_disable(HWND hwnd, HDC  hdc, HGLRC  hrc);



int main(int argc, char** argv)
{
	HAKO_UNUSED(argc);
	HAKO_UNUSED(argv);

	Hako::Engine engine;
	engine.init();

	Hako::Application::init_start(&engine);


	//
	// Create a window descriptor.
	//
	HINSTANCE module_handle         = GetModuleHandle(NULL);

	WNDCLASSEX window_descriptor;
	window_descriptor.cbSize        = sizeof(WNDCLASSEX);
	window_descriptor.style         = CS_OWNDC;
	window_descriptor.lpfnWndProc   = win32_window_callback;
	window_descriptor.cbClsExtra    = 0;
	window_descriptor.cbWndExtra    = 0;
	window_descriptor.hInstance     = module_handle;
	window_descriptor.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	window_descriptor.hCursor       = LoadCursor(NULL, IDC_ARROW);
	window_descriptor.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	window_descriptor.lpszMenuName  = NULL;
	window_descriptor.lpszClassName = "Hako Game Engine";
	window_descriptor.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&window_descriptor))
		return -1;


	//
	// Instantiate and show window to user.
	//
	win32_hwnd_main = CreateWindowEx(0,
		"Hako Game Engine", "Hako Game Engine",
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		960, 544, NULL, NULL, module_handle, NULL);

	ShowWindow(win32_hwnd_main, true);


#ifdef HAKO_BUILD_GFXOPENGL
	//
	// Initialize OpenGL for the window.
	//
	win32_opengl_enable(win32_hwnd_main, &win32_hdc, &win32_hrc);
#endif


	Hako::Application::init_end(&engine);


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
		QueryPerformanceFrequency(&timer_frequency);
		QueryPerformanceCounter(&timer_starttime);

		//
		// Process all queued Win32 event messages.
		//
		MSG window_message;
		while (PeekMessage(&window_message, NULL, 0, 0, PM_REMOVE))
		{
			if (window_message.message == WM_QUIT)
			{
				goto quit;
			}
			else
			{
				TranslateMessage(&window_message);
				DispatchMessage(&window_message);
			}
		}

		//
		// Process frame-syncronized tasks.
		//

		// interpolation factor: (fixed_timer / float(1000000 / fixed_cycles_per_second))
		for (unsigned int i = 0; i < engine.m_framesync_tasks.m_tasks.get_length(); i++)
			engine.m_framesync_tasks.m_tasks.get_element(i).m_entry_point.call(&engine);

	#ifdef HAKO_BUILD_GFXOPENGL
		Hako::common_opengl_render();
		SwapBuffers(win32_hdc);
	#endif

		//
		// Sleep for the remaining of frame.
		//
		LARGE_INTEGER timer_elapsed_microseconds;
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
				engine.m_fixedsync_tasks.m_tasks.get_element(i).m_entry_point.call(&engine);
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

quit:
#ifdef HAKO_BUILD_GFXOPENGL
	//
	// Deinitialize OpenGL for the window.
	//
	win32_opengl_disable(win32_hwnd_main, win32_hdc, win32_hrc);
#endif

	return 0;
}



LRESULT CALLBACK win32_window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//
	// Switch on the message kind.
	//
	switch (uMsg)
	{
		case WM_CLOSE:
			PostQuitMessage(0);
			break;

		case WM_DESTROY:
			return 0;

		case WM_KEYDOWN:
		{
			switch (wParam)
			{
			case VK_ESCAPE:
				PostQuitMessage(0);
				break;
			}
		}
			break;

		default:
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

	return 0;
}



void win32_opengl_enable(HWND hwnd, HDC* hdc, HGLRC* hrc)
{
	PIXELFORMATDESCRIPTOR pfd;
	int iFormat;

	*hdc = GetDC(hwnd);
	ZeroMemory(&pfd, sizeof(pfd));
	pfd.nSize      = sizeof(pfd);
	pfd.nVersion   = 1;
	pfd.dwFlags    = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 24;
	pfd.cDepthBits = 16;
	pfd.iLayerType = PFD_MAIN_PLANE;

	iFormat = ChoosePixelFormat(*hdc, &pfd);
	SetPixelFormat(*hdc, iFormat, &pfd);

	*hrc = wglCreateContext(*hdc);
	wglMakeCurrent(*hdc, *hrc);
}



void win32_opengl_disable(HWND hwnd, HDC hdc, HGLRC hrc)
{
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(hrc);
	ReleaseDC(hwnd, hdc);
}



#endif

