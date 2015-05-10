#ifdef HAKO_BUILD_WIN32


#include "app.h"
#include "../gfx_opengl/init.h"
#include "../gfx_opengl/render.h"
#include <windows.h>


// Window callback function used by Win32.
LRESULT CALLBACK win32_window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


namespace HakoInternal
{
	int Win32App::init(Hako::Options* options)
	{
		HINSTANCE module_handle = GetModuleHandle(NULL);

		// Create a window descriptor.
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

		// Instantiate and show window to user.
		m_hwnd_main = CreateWindowEx(0,
			"Hako Game Engine", "Hako Game Engine",
			WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
			960, 544, NULL, NULL, module_handle, NULL);

		ShowWindow(m_hwnd_main, true);

	#ifdef HAKO_BUILD_GFXOPENGL
		OpenGL::win32_enable(m_hwnd_main, &m_hdc, &m_hrc);
	#endif

		return 0;
	}


	int Win32App::main_loop(Hako::Options* options)
	{
		// Infinite loop. Can only break when user quits the application.
		for (;;)
		{
			// Process Win32 window messages.
			MSG window_msg;
			while (PeekMessage(&window_msg, NULL, 0, 0, PM_REMOVE))
			{
				if (window_msg.message == WM_QUIT)
				{
					goto quit;
				}
				else
				{
					TranslateMessage(&window_msg);
					DispatchMessage(&window_msg);
				}
			}

		#ifdef HAKO_BUILD_GFXOPENGL
			OpenGL::render();
			OpenGL::win32_swap_buffers(m_hwnd_main, &m_hdc, &m_hrc);
		#endif
		}


		quit:

		return 0;
	}
}


LRESULT CALLBACK win32_window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
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


#endif

